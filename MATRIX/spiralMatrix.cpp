class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty())
            return ans;

        int p = 0, q = matrix[0].size() - 1, r = 0, t = matrix.size() - 1;

        while (p <= q && r <= t)
        {
            for (int i = p; i <= q; i++)
            {
                ans.push_back(matrix[r][i]);
            }
            r++;

            for (int i = r; i <= t; i++)
            {
                ans.push_back(matrix[i][q]);
            }
            q--;

            if (r <= t)
            {
                for (int i = q; i >= p; i--)
                {
                    ans.push_back(matrix[t][i]);
                }
                t--;
            }

            if (p <= q)
            {
                for (int i = t; i >= r; i--)
                {
                    ans.push_back(matrix[i][p]);
                }
                p++;
            }
        }
        return ans;
    }
};