
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (n > m)
            return "";

        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int i = 0, j = 0, map_size = mp.size(), minlen = INT_MAX, start = 0;
        // for(auto i: mp) cout<< i.first << i.second << endl;

        while (j < m) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    map_size--;
                }
            }

            while (map_size == 0) {
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        map_size++;
                }
                i++;
            }
            j++;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    };
};