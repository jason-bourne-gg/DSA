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

    int trap(std::vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = std::max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max = std::max(right_max, height[j]);
            }
        }
        return sum;
    }
};