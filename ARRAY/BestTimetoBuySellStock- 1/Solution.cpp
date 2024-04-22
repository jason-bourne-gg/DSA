
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        for ( auto price : prices) {
            if(price<minPrice) minPrice = price;

            int profitToday = price - minPrice;

            if (profitToday> maxProfit) {
                maxProfit = profitToday;
            }
        }
        return maxProfit;
    }
};