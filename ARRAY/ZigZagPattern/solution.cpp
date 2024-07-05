/* Nice Problem */

// PAYPALISHIRING
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
        vector<string> ans(numRows, "");
        int currRow = 0;
        bool goDown = false;

        for (auto i : s)
        {
            // P
            ans[currRow] += i;
            // ["P", "", ""]
            if (currRow == 0 || currRow == numRows - 1)
                goDown = !goDown;
            // true
            currRow += goDown ? 1 : -1;
            // 1
        }

        string gg = "";
        for (auto i : ans)
            gg += i;
        return gg;
    }
};