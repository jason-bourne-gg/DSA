class Solution {
public:
/* 
map to store mapping of chars from S -> t
set to store unique t so that we don't assign two chars of s to single char of t;
 */
    bool isIsomorphic(string s, string t) {
        unordered_map < char,char > mp;
        set<char> st;

        if(s.size() != t.size()) return false;

        for (int i=0; i< s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                 if(mp[s[i]] != t[i]) return false;

            }
            else
                if (st.find(t[i]) != st.end()) return false;
                mp[s[i]] = t[i];
                st.insert(t[i]);
        }
        return true;
    }
};