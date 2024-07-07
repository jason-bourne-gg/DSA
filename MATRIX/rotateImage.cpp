#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate90(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

void rotate180(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    reverse(matrix.begin(), matrix.end());
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    Solution sol;

    // Rotate 90 degrees
    sol.rotate90(matrix);
    cout << "\nMatrix rotated by 90 degrees:" << endl;
    printMatrix(matrix);

    // Rotate back to original position for next test
    sol.rotate90(matrix);
    sol.rotate90(matrix);
    sol.rotate90(matrix);

    // Rotate 180 degrees
    rotate180(matrix);
    cout << "\nMatrix rotated by 180 degrees:" << endl;
    printMatrix(matrix);

    return 0;
}
