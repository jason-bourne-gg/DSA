#include <iostream>
#include <vector>
#include <map> 
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> occurrenceMap; //char, freq
        
        for (auto i : s) {
            if (occurrenceMap.find(i) == occurrenceMap.end()) {
                occurrenceMap[i] = 1;
            } else {
                occurrenceMap[i]++;
            }
        }

        for(int i=0;i<s.size();i++){
            if(occurrenceMap[s[i]]==1){
                return i;
            }
        }

        // char c;
        // for (auto j : occurrenceMap) {
        //     if (j.second == 1) {
        //         cout<< j.first << " ";
        //         c =j.first;
        //     }
        // }
        // cout<< c;

        // for (auto k: s) {
        //     return s.find(c);
        // }
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "loveleetcode";

    int index = solution.firstUniqChar(s);
    cout << index << " ";

    cout << endl;

    return 0;
}
