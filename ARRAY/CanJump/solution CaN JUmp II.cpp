class Solution {
public:
     int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }
};

/* The first loop modifies nums[i] to hold the maximum index we go up to in a single jump from i

nums[i-1] already contains maximum we can reach upto from i-1
for the ith element, we can go further if nums[i] + i > (modified)nums[i-1]
if not, we are better off by jumping from i-1 itself, and never reaching i

The second loop simply accumlates the count of these maximised jumps. */