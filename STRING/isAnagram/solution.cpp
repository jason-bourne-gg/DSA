/*  Javascript solution */

var isAnagram = function(s, t) {
    return s.split("").sort().join() === t.split("").sort().join()
};

/* C++ solution */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> mp;

        for (auto i : s) {
            if (mp.find(i) == mp.end())
                mp[i] = 1;
            else
                mp[i]++;
        }

        for (auto j : t) {
            if (mp.find(j) == mp.end())
                return false;
            else if (mp[j] == 0)
                return false;
            else
                mp[j]--;
        }
        return true;
    }
};