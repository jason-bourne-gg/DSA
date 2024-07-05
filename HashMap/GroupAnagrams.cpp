class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            string strTemp = strs[i];
            sort(strTemp.begin(), strTemp.end());
            mp[strTemp].push_back(strs[i]);
        }
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};