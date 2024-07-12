#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // for reverse

using namespace std;

string reverseParentheses(string s)
{
    stack<string> st;
    string temp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(temp); // Push the current temp string onto the stack
            temp = "";     // Reset temp for the new substring
        }
        else if (s[i] == ')')
        {
            reverse(temp.begin(), temp.end()); // Reverse the current substring
            if (!st.empty())
            {
                temp = st.top() + temp; // Concatenate with the top of the stack
                st.pop();               // Remove the top element from the stack
            }
            // st.push(temp);
            // no need for this..becos we already have a pre prev + curr + coming sub str
        }
        else
        {
            temp += s[i]; // Append the current character to temp
        }
    }

    return temp;
}

int main()
{
    string s = "(ed(et(oc))el)";
    cout << reverseParentheses(s) << endl; // Output should be "leetcode"
    return 0;
}
