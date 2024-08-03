class Solution
{
public:
    int mySqrt(int x)
    {
        // easy way is
        // return pow(x, 0.5);

        /* using binay search */
        if (x == 0)
            return 0;
        int hi = x;
        int lo = 0;
        int mid;
        while (hi >= lo)
        {
            mid = lo + (hi - lo) / 2;
            long long int square = mid * mid;

            if (square == x)
                return (int)mid;

            if (square > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return (int)hi;
    }
};