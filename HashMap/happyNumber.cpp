class Solution {
public:
    int nextNumber (int n ){
        int newNumber = 0;
        while(n!=0){
            int remainder = n%10;
            int quo = n/10;
            cout << remainder << " " <<  quo <<endl;
            newNumber += remainder*remainder;
            n = quo;
        }
        return newNumber;
    }

    bool isHappy(int n) { 
        unordered_set<int> set; 

        while(n!=1 && set.count(n) == 0) {
            set.insert(n);
            n=nextNumber(n);
        }

        return n==1;
    }
};