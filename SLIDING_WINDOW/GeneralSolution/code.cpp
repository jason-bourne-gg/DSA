int minSubArrayLen(int target, vector<int>& nums) {
            int i = 0;
            int j = 0;
            int mini = 1e9; //INT_MAX
            int sum = 0;
            while(j<nums.size()){
                sum = sum + nums[j];
                if(sum<target){
                    j++;
                }
                else if(sum == target){
                    mini = min(mini,j-i+1);
                    j++;
                }else{
                    while(sum>=target){
                        mini = min(mini,j-i+1);
                        sum = sum-nums[i];
                        i++;
                    }
                    j++;
                }
            }
            if(mini == 1e9){
                return 0;
            }
            return mini;
    }