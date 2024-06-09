class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), ans = 0;
        unordered_map <char,int> mp;


        while (j < n) {
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] = j;
                ans = max(ans, j-i +1);
                j++;
            }
            else {
                mp.erase(s[i]);
                cout << ans <<endl;
                i++;
            }
        }
        return ans;
    }
};