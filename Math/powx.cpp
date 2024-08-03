/* class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        if (n > 0) {
            for (int i = 0; i < n; i++) {
                ans = ans * x;
            }
        } else {
            cout << "-ve" << endl;
            for (int i = 0; i < -n; i++) {
                ans = ans / x;
            }
        }
        return ans;
    }


};

/* Your implementation of the myPow function calculates x ^n
  by repeatedly multiplying or dividing ans by x. While this works, it is not
efficient for large values of n due to its linear time complexity 𝑂(𝑛 A more
efficient approach is to use Exponentiation by Squaring, which has a time
complexity of 𝑂(log 𝑛). This method reduces the number of multiplicatio
s required by leveraging the properties of exponents. */

class Solution
{
public:
    double myPow(double x, int n)
    {
        // Handle the special case where n is the minimum integer value
        // This avoids overflow when negating n (since abs(INT_MIN) is greater than INT_MAX)
        if (n == INT_MIN)
        {
            x = 1 / x;
            n = INT_MAX;
            return x * myPow(x, n - 1);
        }

        // If n is negative, compute the positive power and take the reciprocal
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        double result = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            n /= 2;
        }
        return result;
    }
};
