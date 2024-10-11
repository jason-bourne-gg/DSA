class Solution
{
private:
    void backtrack(int open, int close, string &temp, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (open > 0)
        {
            temp.push_back('('); // Add an open parenthesis
            backtrack(open - 1, close, temp, ans);
            temp.pop_back(); // Backtrack by removing the last character
        }

        if (close > open)
        {
            temp.push_back(')'); // Add a close parenthesis
            backtrack(open, close - 1, temp, ans);
            temp.pop_back(); // Backtrack by removing the last character
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;

        backtrack(n, n, temp, ans);

        return ans;
    }
};
