class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n); //stores product of left ele till ith postion
        vector<int> right_Product(n); //stores product of right eles till ith postion
        left_Product[0] = nums[0];
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i];
        }
        right_Product[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i];
        }
        ans[0] = right_Product[1]; //handling edge cases
        ans[n-1] = left_Product[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = left_Product[i-1] * right_Product[i+1];
        }
        return ans;
    }
};
