#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        int l = 0;
        int m = arr[0].size() - 1;
        vector<int> ans;

        while (i <= j && l <= m) {
            // Traverse the top row from left to right
            for (int k = l; k <= m; ++k) {
                ans.push_back(arr[i][k]);
            }
            ++i;

            // Traverse the rightmost column from top to bottom
            for (int k = i; k <= j; ++k) {
                ans.push_back(arr[k][m]);
            }
            --m;

            // Traverse the bottom row from right to left
            if (i <= j) {
                for (int k = m; k >= l; --k) {
                    ans.push_back(arr[j][k]);
                }
                --j;
            }

            // Traverse the leftmost column from bottom to top
            if (l <= m) {
                for (int k = j; k >= i; --k) {
                    ans.push_back(arr[k][l]);
                }
                ++l;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example 2D vector
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Get the spiral order traversal
    vector<int> result = solution.spiralOrder(arr);

    // Print the result
    cout << "Spiral order traversal:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
