#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool wordBreakHelp(string s, unordered_set<string> &set, vector<int> &dp, int start)
    {
        if (start == s.size())
        {
            return true;
        }

        if (dp[start] != -1)
        {
            return dp[start];
        }

        for (int i = start; i < s.size(); i++)
        {
            if (set.find(s.substr(start, i + 1 - start)) != set.end() &&
                wordBreakHelp(s, set, dp, i + 1))
            {
                dp[start] = true;
                return true;
            }
        }
        dp[start] = false; // Mark as not possible
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, 0); // dp[i] means whether s[0:i] can be segmented
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        dp[0] = 1; // Empty string can always be segmented

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && set.find(s.substr(j, i - j)) != set.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (solution.wordBreak(s, wordDict))
    {
        cout << "The string \"" << s << "\" can be segmented." << endl;
    }
    else
    {
        cout << "The string \"" << s << "\" cannot be segmented." << endl;
    }

    return 0;
}
