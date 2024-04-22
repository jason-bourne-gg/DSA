class Solution {
public:
  bool canJump(vector<int>& nums) {
    int maxReach = 0;  // Tracks the maximum index that can be reached.

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) {a
            // If i is beyond the maximum reach, you cannot proceed further.
            return false;
        }
        // Update maxReach to be the maximum of itself or the reach from the current index.
        maxReach = max(maxReach, i + nums[i]);
        if (maxReach >= nums.size() - 1) {
            // If you can reach or exceed the last index, return true.
            return true;
        }
    }

    // If you finish the loop without having returned, it means you're stuck.
    return false;
}
};