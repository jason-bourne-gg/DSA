class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> set;
        // for (int num : nums) {
        //     set.insert(num);
        // }
        // int longestConsecutiveSequence = 0;
        // for (int num : nums) {
        //     if (set.find(num - 1) == set.end()) {
        //         int currentNumber = num;
        //         int currentConsecutiveSequence = 1;
        //         while (set.find(currentNumber + 1) != set.end()) {
        //             currentNumber++;
        //             currentConsecutiveSequence++;
        //         }
        //         longestConsecutiveSequence =
        //             max(longestConsecutiveSequence,
        //             currentConsecutiveSequence);
        //     }
        // }
        // return longestConsecutiveSequence;
        int n = nums.size();
        if (n < 2)
            return n;

        sort(nums.begin(), nums.end());
        int longestConsecutive = 1;
        int count = 1;
        for (int i = 0; i < nums.size() - 1; i++) {

            if (nums[i + 1] - nums[i] == 1) {
                count++;
            } else if (nums[i + 1] - nums[i] == 0) {
                continue;
            } else {
                longestConsecutive = max(count, longestConsecutive);
                count = 1;
            }
        }
        longestConsecutive = max(count, longestConsecutive);
        return longestConsecutive;
    }
};