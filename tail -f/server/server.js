import express from "express";
import { WebSocketServer } from "ws";
import { watch, createReadStream } from "fs";
import fs from "fs";
import WebSocket from "ws";
import path from "path";
import { fileURLToPath } from "url";
import { promisify } from "util";

// ES Module dirname equivalent
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

// Configuration
const PORT = 5001;
const LOG_FILE_PATH = path.join(__dirname, '../logs/remoteLogFile.log');
const LINES_TO_READ = 10;

// Initialize Express server
const app = express();
const server = app.listen(PORT, () => {
  console.log(`Server Listening at Port: http://localhost:${PORT}`);
});

// Initialize WebSocket server
const wss = new WebSocketServer({ server });

/**
 * Gets the last N lines from a file
 * @param {string} filePath - Path to the file
 * @param {number} n - Number of lines to read
 * @returns {Promise<string>} - Last N lines of the file
 */
async function getLastNLines(filePath, n) {
  // Get file stats to know its size
  const stat = await promisify(fs.stat)(filePath);
  const fileSize = stat.size;
  
  // Buffer to hold data read from file
  const lines = [];
  let bytesRead = 0;
  let position = fileSize;
  
  // Default chunk size (adjust based on average line length)
  const chunkSize = 1024 * 100; // 100KB chunks
  
  // Create file handle
  const fileHandle = await promisify(fs.open)(filePath, 'r');
  
  try {
    // Read chunks from the end of the file until we have enough lines or reach the beginning
    while (position > 0 && lines.length < n + 1) {
      // Adjust chunk size for the last read
      const size = Math.min(chunkSize, position);
      position -= size;
      
      // Allocate buffer and read chunk
      const buffer = Buffer.alloc(size);
      await promisify(fs.read)(fileHandle, buffer, 0, size, position);
      
      // Convert buffer to string and split into lines
      let chunk = buffer.toString('utf8');
      
      // If this isn't the first chunk and we don't start with a newline,
      // we need to combine with the beginning of our accumulated content
      if (lines.length > 0 && !chunk.endsWith('\n')) {
        const lastLine = lines.shift();
        chunk += lastLine;
      }
      
      // Prepend new lines to our array
      const newLines = chunk.split('\n');
      lines.unshift(...newLines);
      
      bytesRead += size;
    }
    
    // Return last n lines
    return lines.slice(-n).join('\n');
  } finally {
    // Close the file handle
    await promisify(fs.close)(fileHandle);
  }
}

/**
 * Broadcasts a message to all connected WebSocket clients
 * @param {string} data - Data to broadcast
 */
const broadcastToClients = (data) => {
  wss.clients.forEach(client => {
    if (client.readyState === WebSocket.OPEN) {
      client.send(data);
    }
  });
};

// Watch the log file for changes
try {
  watch(LOG_FILE_PATH, async (eventType, filename) => {
    if (eventType === 'change' && filename) {
      console.log(`Change detected in: ${filename}`);
      try {
        const updates = await getLastNLines(LOG_FILE_PATH, LINES_TO_READ);
        broadcastToClients(updates);
      } catch (error) {
        console.error("Failed to process log update:", error);
      }
    }
  });
} catch (error) {
  console.error("Failed to watch log file:", error);
}

// Handle WebSocket connections
wss.on('connection', async (client) => {
  console.log("New client connected");
  try {
    const initialContent = await getLastNLines(LOG_FILE_PATH, LINES_TO_READ);
    client.send(initialContent);
  } catch (error) {
    console.error("Failed to send initial content to client:", error);
    client.send("Error loading log content. Please try again later.");
  }

  client.on('error', (error) => {
    console.error("WebSocket client error:", error);
  });

  client.on('close', () => {
    console.log("Client disconnected");
  });
});

// Basic health check endpoint
app.get('/health', (req, res) => {
  res.status(200).send('Server is running');
});

// Error handling for unhandled errors
process.on('uncaughtException', (error) => {
  console.error('Uncaught Exception:', error);
});

process.on('unhandledRejection', (reason, promise) => {
  console.error('Unhandled Promise Rejection:', reason);
});