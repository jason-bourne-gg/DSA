class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> reverse_mp;
        int n = pattern.size();
        vector<string> v;
        string temp = "";

        // Split the input string into words
        stringstream ss(s);
        while (ss >> temp) {
            v.push_back(temp);
        }

        // If the number of words and the length of the pattern are different,
        // return false
        if (v.size() != n)
            return false;

        for (int k = 0; k < n; ++k) {
            char c = pattern[k];
            string word = v[k];

            // Check if the current pattern character has been mapped to a word
            if (mp.find(c) != mp.end()) {
                if (mp[c] != word)
                    return false;
            } else {
                mp[c] = word;
            }

            // Check if the current word has been mapped to a pattern character
            if (reverse_mp.find(word) != reverse_mp.end()) {
                if (reverse_mp[word] != c)
                    return false;
            } else {
                reverse_mp[word] = c;
            }
        }

        return true;
    }
};