class Solution
{
private:
    void backtrack(vector<int> &candidates, vector<int> &temp,
                   vector<vector<int>> &ans, int target, int idx)
    {
        // Base case: If the target becomes zero, we found a valid combination
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // If the target is less than zero or if we've processed all candidates,
        // stop recursion
        if (target < 0 || idx >= candidates.size())
        {
            return;
        }

        // Recursive case 1: Exclude the current candidate and move to the next
        backtrack(candidates, temp, ans, target, idx + 1);

        // Recursive case 2: Include the current candidate and recurse with the
        // same index (to reuse it)
        temp.push_back(candidates[idx]);
        backtrack(candidates, temp, ans, target - candidates[idx],
                  idx);  // Reuse the current element
        temp.pop_back(); // Backtrack: remove the element added in this
                         // recursion
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans; // Result array
        vector<int> temp;        // Temporary array to store current combination

        // Start backtracking from index 0
        backtrack(candidates, temp, ans, target, 0);

        return ans; // Return the list of valid combinations
    }
};
