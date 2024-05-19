class Solution {
public:
    /*
    0 1 0 3 1 0 1 3 2 1 2 1
    0 1 1 3 3 3 3 3 3 3 3 3
    3  3  3  3  3  3  3  3  2  2 2 1
     */
    /* int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0)
                leftMax[i] = height[i];
            else
                leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                rightMax[i] = height[i];
            else
                rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += min(leftMax[i], rightMax[i]) * 1 - height[i];
        }
        return totalSum;
    }

    O(n) time and O(n) space
     */

int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int left_max=0,right_max=0; 
        int ans=0;

        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>left_max) left_max=height[left];
                else ans+= left_max-height[left];
                left++;
            }
            else{
                if(height[right]>right_max) right_max=height[right];
                else ans+= right_max-height[right];
                right--;
            }
        }

        return ans;
    }
};