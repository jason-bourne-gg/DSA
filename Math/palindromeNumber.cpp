class Solution
{
public:
    bool isPalindrome(int x)
    {
        string numString = to_string(x);
        string reversedNumString = numString;
        reverse(reversedNumString.begin(), reversedNumString.end());
        return reversedNumString == numString;
    }
};