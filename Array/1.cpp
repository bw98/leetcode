//Runtime: 106 ms
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {             
        int i,j;
        vector<int> ret {0, 1};
        for (i = 0; i< nums.size(); ++i) {
            ret[0] = i;
            for(j = i+1; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target) 
                {    
                    ret[1] = j;
                    return ret;
                }                                                          
            }                                                              
        }                                 
    }                                                                    
};                                    
                                           
//Runtime: 79 ms
//Because nums[i], nums[j], target are fixed values, we do not need to do additions every time
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {             
        int i,j;
        vector<int> ret {0, 1};
        for (i = 0; i< nums.size(); ++i) {
            ret[0] = i;
            int tar = target - nums[i];
            for(j = i+1; j < nums.size(); ++j){
                if (nums[j] == tar) 
                {    
                    ret[1] = j;
                    return ret;
                }                                                          
            }                                                              
        }                                 
    }                                                                    
};                                    

