class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            // while (j + 1 < nums.size() && nums[j + 1] - nums[j] == 1)
            /* above line will throw an eerror when nums[j+1] = INT MAX and nums[j] = INT_MIN
             causing out of Int limit*/
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
                j++;
            if (j == i)
            {
                ans.push_back(to_string(nums[i]));
            }
            else
            {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j;
        }
        return ans;
    }
};