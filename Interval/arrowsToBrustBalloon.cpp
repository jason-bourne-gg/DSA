
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int ans = 1;
        int n = points.size();
        sort(points.begin(), points.end());
        int left = points[0][0], right = points[0][1];

        for (int i = 1; i < n; i++)
        {
            int x1 = points[i][0], x2 = points[i][1];

            if (x1 <= right)
            {
                right = min(x2, right);
            }
            else
            {
                left = x1;
                right = x2;
                ans++;
            }
        }
        return ans;
    }
};