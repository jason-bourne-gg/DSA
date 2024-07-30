class Solution
{
private:
    int helper(int idx, vector<int> &dp, vector<int> nums)
    {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = max(nums[idx] + helper(idx - 2, dp, nums),
                             helper(idx - 1, dp, nums));
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(n - 1, dp, nums);
    }
};

/* Recursion will go exponential time 2^n.
 Hence we use array to store recursion function calls to brin time complexity to O(n) */