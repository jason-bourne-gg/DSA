import React, { useEffect, useState } from "react";

function App() {
  const [logs, setLogs] = useState([]);
  const [connected, setConnected] = useState(false);

  useEffect(() => {
    // Fetching data from websocket
    // Note: WebSocket URLs use ws:// protocol, not http://
    const ws = new WebSocket('ws://localhost:5001');
    
    ws.onopen = () => {
      setConnected(true);
    };

    ws.onmessage = (event) => {
      setLogs(event.data.split('\n').filter(line => line.trim() !== ''));
    };
    
    ws.onclose = () => {
      setConnected(false);
    };

    // Closing websocket when component unmounts
    return () => {
      if (ws) ws.close();
    };
  }, []);

  return (
    <div style={{ 
      padding: '20px', 
      fontFamily: 'monospace',
      maxWidth: '1200px',
      margin: '0 auto',
      backgroundColor: '#f5f5f5',
      minHeight: '100vh'
    }}>
      <h1 style={{
        borderBottom: '2px solid #333',
        paddingBottom: '10px',
        marginBottom: '20px'
      }}>
        LOGS FETCHED FROM SERVER
        <span style={{
          display: 'inline-block',
          width: '10px',
          height: '10px',
          borderRadius: '50%',
          backgroundColor: connected ? 'green' : 'red',
          marginLeft: '10px'
        }}></span>
      </h1>
      
      <div style={{ 
        background: '#282c34', 
        border: '1px solid #ccc',
        borderRadius: '5px',
        height: '80vh', 
        width: '100%', 
        overflowY: 'auto',
        padding: '10px',
        boxShadow: '0 2px 4px rgba(0,0,0,0.1)'
      }}>
        {logs.length > 0 ? (
          logs.map((line, index) => (
            <div key={index} style={{ 
              color: '#f8f8f2',
              padding: '4px 0',
              borderBottom: '1px solid #3a3d45',
              fontFamily: 'monospace',
              fontSize: '14px',
              whiteSpace: 'pre-wrap',
              wordBreak: 'break-all'
            }}>
              {line}
            </div>
          ))
        ) : (
          <div style={{ color: '#999', textAlign: 'center', marginTop: '20px' }}>
            {connected ? 'Waiting for logs...' : 'Not connected to server'}
          </div>
        )}
      </div>
    </div>
  );
}

export default App;