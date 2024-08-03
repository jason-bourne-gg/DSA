class Solution
{
private:
    int fact(int n)
    {
        vector<int> ans(n + 1);
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        ans[0] = 1;
        ans[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            ans[i] = i * fact(i - 1);
        }
        return ans[n];
    }

public:
    int trailingZeroes2(int n)
    {

        int ans = fact(n);
        string ans2 = to_string(ans);

        cout << ans2 << endl;

        int count = 0;
        for (int i = ans2.size() - 1; i >= 0; i--)
        {
            if (ans2[i] == '0')
                count++;
            else
                break;
        }

        return count;
    }
    /* Inefficient Factorial Calculation: The recursive fact function within
    your fact function can lead to a high number of redundant calculations and a
    potential stack overflow for larger values of n. Large Number Handling:
    Calculating the factorial of large numbers directly and converting them to
    strings is computationally expensive and impractical due to the size of the
    numbers involved. Unnecessary Vector Usage: Using a vector to store
    intermediate results of factorials isn't needed here.
    */
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};