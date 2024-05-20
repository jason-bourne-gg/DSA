class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }
        for (auto triplet : s) {
            ans.push_back(triplet);
        }
        return ans;
    }
};