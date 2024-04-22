class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp ;

        for (int i=0 ; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end())
                mp[nums[i]] ++;
            else mp[nums[i]] = 1;    
        }

        for (auto entry: mp){
            if (entry.second > nums.size()/2)
            return entry.first;
        }

        return -1;
    }
};


/* MOORE's voting algo */

/* class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (auto i: nums){
            if(count == 0){
                candidate = i;
            }
            if (i == candidate ){
                count ++;
            }
            else count --;
        }
        return candidate;
    }
}; */



// For element occuring > n/3 
/* vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;

    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        if (num == candidate2) count2++;
    }

    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    return result;
}
 */