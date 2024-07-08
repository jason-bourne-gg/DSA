class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> ansi;
        vector<int> ansj;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    ansi.push_back(i);
                    ansj.push_back(j);
                }
            }
        }

        for (auto x : ansi)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[x][j] = 0;
        }

        for (auto y : ansj)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][y] = 0;
        }
    }
};