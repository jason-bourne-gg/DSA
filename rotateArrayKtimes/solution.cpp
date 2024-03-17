#include <stdio.h>
#include <iostream>
using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k = k % n; // for right rotate
    k = n - k; // for left rotate (comment this line for right rotate)
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0,  k-1);
    reverse(nums, k, nums.size()-1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 2);
    for(auto i: nums) cout << i << " ";
    cout << endl;
}
