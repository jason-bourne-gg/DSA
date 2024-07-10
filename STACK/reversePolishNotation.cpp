class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;

        for (auto x : tokens)
        {
            if (x != "+" && x != "-" && x != "*" && x != "/")
            {
                s.push(stoi(x));
            }
            else
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                int ans;
                if (x == "+")
                {
                    ans = first + second;
                }
                else if (x == "-")
                {
                    ans = first - second;
                }
                else if (x == "*")
                {
                    ans = first * second;
                }
                else if (x == "/")
                {
                    if (second == 0)
                        throw runtime_error("Division by zero");
                    ans = first / second;
                }
                s.push(ans);
            }
        }
        return s.top();
    }
};