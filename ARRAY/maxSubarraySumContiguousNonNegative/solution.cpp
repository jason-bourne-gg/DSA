#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxset(vector<int> &arr) {
        int max_sum = 0;
        int curr_sum = 0;
        int max_length = 0;
        int curr_length = 0;
        int start_index = 0;
        int max_start_index = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= 0) {
                curr_sum += arr[i];
                ++curr_length;
                if (curr_sum > max_sum || (curr_sum == max_sum && curr_length > max_length)) {
                    max_sum = curr_sum;
                    max_length = curr_length;
                    max_start_index = start_index;
                }
            } else {
                curr_sum = 0;
                curr_length = 0;
                start_index = i + 1;
            }
        }

        vector<int> ans(arr.begin() + max_start_index, arr.begin() + max_start_index + max_length);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, -1, 3, 4, -1, 5, 6, 7, -1, -1, 8, 9, 10};
    vector<int> maxSubarray = solution.maxset(arr);
    
    cout << "Maximum sum contiguous subarray: ";
    for (int num : maxSubarray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
