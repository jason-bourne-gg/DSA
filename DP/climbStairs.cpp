class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> ways(n + 1);
        ways[0] = 1;
        ways[1] = 2;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        for (int i = 2; i < n; i++)
        {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n - 1];
    }
};