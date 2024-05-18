class Solution {
public:
/* 
gas  = 1 2 3 4 5
cost = 3 4 5 1 2

gas =  2 3 4
cost = 3 4 3
*/
    int calculateStartIndex(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int startIndex = 0;
        int currentFuel = 0;
        for (int i = 0; i< n; i++){
            currentFuel += gas[i] - cost[i];
            if(currentFuel<0){
                currentFuel = 0;
                startIndex = i+1;
            }
        }

        return startIndex;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuelSum = 0;
        int costSum = 0;
        int n = gas.size();

        for (int i = 0; i< n; i++){
            fuelSum+= gas[i];
            costSum+= cost[i];
        }

        if(fuelSum >= costSum) return calculateStartIndex(gas, cost);

        return -1;


    }
};