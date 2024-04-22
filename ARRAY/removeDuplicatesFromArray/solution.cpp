#include <iostream>
#include <vector>  // Include the vector header file
#include <algorithm>  // Include the algorithm header file for std::unique

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int count = solution.removeDuplicates(nums);
    nums.erase(nums.begin() + count, nums.end()); // Erase elements after k to remove duplicates

    for(auto i: nums) cout << i << " ";
    cout << endl << count << " ";
    cout << endl;
    return 0;
}
