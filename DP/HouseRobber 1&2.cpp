class Solution
{
private:
    // Memoized version of the helper function
    int helper(int idx, vector<int> &dp, vector<int> &nums)
    {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // Choose to rob this house or not
        int take = nums[idx] + helper(idx - 2, dp, nums);
        int notTake = helper(idx - 1, dp, nums);

        return dp[idx] = max(take, notTake);
    }

public:
    // Function to rob houses using memoization
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(n - 1, dp, nums);
    }

    // House Robber 1 - Tabulation version
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }

    // House Robber 1 - Space Optimization version
    int rob3(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev; // coz we are not robbing ith house

            int curri = max(take, notTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
/* Key Points:
Memoized Version (helper function): The helper function uses a memoization technique to store the results of subproblems to avoid recomputation.
Tabulation (rob2 function): This iterative approach builds up the solution from the bottom-up and uses a dp array to store the results.
Space Optimization (rob3 function): This optimized version reduces space complexity by using two variables instead of a dp array.
*/

/* House robber 2  */
// same as house robber 1 but call function twice for 2 arrays
// such that each of that only has either first or last elee in array