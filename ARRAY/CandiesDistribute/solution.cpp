class Solution {
public:
/* 
1 0 2

3

Greedy Algorithm: Two-Pass Method Explained
What is a Greedy Algorithm?
A Greedy Algorithm makes choices that seem optimal at the moment. For this problem, we use a two-pass greedy approach to make sure each child gets the minimum number of candies that still satisfy the conditions.

The Nuts and Bolts of the Two-Pass Method
Initialize Candies Array
We start by creating a candies array of the same length as the ratings array and initialize all its values to 1. This is the base case and ensures that every child will receive at least one candy, satisfying the first condition.

Forward Pass: Left to Right
Now, we iterate through the ratings array from the beginning to the end. For each child (except the first), we compare their rating with the one to the left. If it's higher, we update the candies array for that child to be one more than the child on the left. This takes care of the second condition but only accounts for the child's left neighbor.

Backward Pass: Right to Left
After the forward pass, we loop through the array again but in the reverse direction. This time, we compare each child's rating with the child to their right. If the rating is higher, we need to make sure the child has more candies than the right neighbor. So, we update the candies array for that child to be the maximum between its current number of candies and one more than the right neighbor's candies. This ensures that both neighboring conditions are checked and satisfied.

Summing it All Up
Finally, we sum up all the values in the candies array. This will give us the minimum total number of candies that need to be distributed to satisfy both conditions.
Time and Space Complexity
Time Complexity: O(n)O(n)O(n), because we make two passes through the array.
Space Complexity: O(n)O(n)O(n), for storing the candies array.
 */

    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> candies (n, 1);

        for (int i = 1; i<n; i++){
            if(rating[i]> rating[i-1])
            candies[i] = candies[i-1] + 1;
        }

         for (int i = n-2; i>=0; i--){
            if(rating[i]> rating[i+1])
            candies[i] = max(candies[i],candies[i+1] + 1);
        }

        int totalCandies = accumulate(candies.begin(),candies.end(), 0);

        return totalCandies;
    }
};