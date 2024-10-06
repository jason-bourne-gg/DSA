class Solution
{
private:
    void backtrack(string digits, int idx, string comb, vector<string> &ans,
                   unordered_map<char, string> &mp)
    {
        if (digits.length() == idx)
            ans.push_back(comb);

        string letters = mp[digits[idx]];

        for (auto letter : letters)
        {
            backtrack(digits, idx + 1, comb + letter, ans, mp);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        backtrack(digits, 0, "", ans, mp);

        return ans;
    };
};