class Solution
{
private:
    void backtrack(vector<int> nums, vector<int> &temp, vector<bool> &used,
                   vector<vector<int>> &ans)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (auto i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, temp, used, ans);

            temp.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        // To track which numbers are already used in the current permutation

        backtrack(nums, temp, used, ans);

        return ans;
    }
};