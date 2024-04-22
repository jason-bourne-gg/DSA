#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string factorial(int n) {
        if (n < 0) {
            return "Invalid input";
        }
        if (n == 0 || n == 1) {
            return "1";
        }

        long long int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }

        return to_string(result);
    }
};

int main() {
    Solution solution;
    int n = 100;
    string factorialResult = solution.factorial(n);
    cout << "Factorial of " << n << " = " << factorialResult << endl;
    return 0;
}
