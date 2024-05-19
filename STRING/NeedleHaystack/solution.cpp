class Solution {
public:
    int strStr(string haystack, string needle) {
        int i =0, j=0;
        int startIndex= 0;
        if(needle.size()> haystack.size()) return -1;
        
        for (int i =0; i<= haystack.size()- needle.size(); i++)
        {
            if(haystack.substr(i, needle.length()) == needle) return i;
        }
        return -1;
    }
};