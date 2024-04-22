#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int e = s.size()-1;

        while (start<=e){
            if (s[start] != s[e])
                {
                    return false;
                    break;
                }
            start++;
            e--;    
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "aabbabbaa";

    if (solution.isPalindrome(s)){
        cout<< s <<" is Palindrome " << " " ;
    }
    else 
        cout<< s <<" is not Palindrome " << " " ;

}
