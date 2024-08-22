class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Result vector to store merged intervals
        vector<vector<int>> ans;

        // Return empty if there are no intervals
        if (intervals.empty())
            return ans;

        // Sort the intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        // Initialize the first interval to be merged
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            // Check if the current interval overlaps with the next one
            if (intervals[i][0] <= current[1])
            {
                // Merge by updating the end time to the maximum
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                // Push the merged interval to the result and start a new merge
                ans.push_back(current);
                current = intervals[i];
            }
        }

        // Push the last interval after the loop
        ans.push_back(current);

        return ans;
    }
};
