#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWords(string s) {
    stack<string> stk;
    int i = 0, j = s.size() - 1;
    string ans;

    // Remove leading spaces
    while (i <= j && s[i] == ' ') i++;
    // Remove trailing spaces
    while (j >= i && s[j] == ' ') j--;

    string temp = "";
    // Traverse the trimmed string
    for (int k = i; k <= j; ++k) {
        if (s[k] != ' ') {
            temp += s[k];
        } else if (temp != "") {
            stk.push(temp);
            temp = "";
            // Skip all subsequent spaces
            while (k <= j && s[k] == ' ') k++;
            k--;  // Adjust for the extra increment in the loop
        }
    }
    // Push the last word if it exists
    if (temp != "") {
        stk.push(temp);
    }

    // Construct the reversed words string
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
        if (!stk.empty()) {
            ans += ' ';
        }
    }
    return ans;
}

int main() {
    string test = "  hello    world  ";
    cout << "\"" << reverseWords(test) << "\"" << endl;
    return 0;
}
