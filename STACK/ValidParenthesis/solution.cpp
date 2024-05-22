class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {
            {')', '('}, {']', '['}, {'}', '{'}};

        if (s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else if (!stk.empty()) {
                char chut = stk.top();
                // cout << chut << mapping[c] << endl;
                if (mapping[c] != chut)
                    return false;
                else
                    stk.pop();
            } else
                return false;
        }
        return stk.empty();
    }
};