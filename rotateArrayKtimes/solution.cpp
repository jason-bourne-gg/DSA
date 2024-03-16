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

    k = k % n;
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0,  k-1);
    reverse(nums, k, nums.size()-1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate(nums, 6);
    for(auto i: nums) cout << i;
}
