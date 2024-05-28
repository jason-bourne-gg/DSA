class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), sum = 0, ans = INT_MAX;

        while (j < n) {
            sum += nums[j];

            if (sum >= target) {
                ans = min(ans, j - i + 1);
                sum = sum - nums[i];
                i++;
            }
            j++; //if sum<target
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};