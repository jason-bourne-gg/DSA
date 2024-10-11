class Solution
{
private:
    void backtrack(vector<int> &nums, int k, int idx, vector<int> &temp,
                   vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            if (temp.size() == k) // If u remove this line...then it will generate all subsets all all lnegths
                ans.push_back(temp);
            return;
        }

        backtrack(nums, k, idx + 1, temp, ans);
        temp.push_back(nums[idx]);
        backtrack(nums, k, idx + 1, temp, ans);
        temp.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> nums; // to store all nums
        vector<int> temp; // to store current subset

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }

        backtrack(nums, k, 0, temp, ans);

        return ans;
    }
};