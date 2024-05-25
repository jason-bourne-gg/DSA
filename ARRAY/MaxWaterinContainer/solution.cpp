int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int maxArea = 0;

        while (l < r) {
            maxArea = max(maxArea, min(height[l], height[r]) * (r-l));

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }