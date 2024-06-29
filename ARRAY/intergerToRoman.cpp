class Solution {
public:
    string intToRoman(int num) {
        // unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
        //                                {'L', 50},  {'C', 100}, {'D', 500},
        //                                {'M', 1000}};

        // for (auto i : mp)
        //     cout << i.first << i.second << endl;

        // if(num>1000) num=num%1000

        vector<string> ones = {"",  "I",  "II",  "III",  "IV",
                               "V", "VI", "VII", "VIII", "IX"};
        vector<string> tens = {"",  "X",  "XX",  "XXX",  "XL",
                               "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hundreds = {"",  "C",  "CC",  "CCC",  "CD",
                                   "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> thousands = {"", "M", "MM", "MMM"};

        return thousands[num / 1000] + hundreds[(num % 1000) / 100] +
               tens[(num % 100) / 10] + ones[num%10];
    }
};