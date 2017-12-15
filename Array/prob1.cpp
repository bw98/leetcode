/*************************************************************************
	> File Name: prob1.cpp
	> Author: bw98 
	> Mail: 
	> Created Time: 2017年12月15日 星期五 19时45分35秒
 ************************************************************************/
 
//Runtime: 106 ms
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {             
        int i,j;
        int index1 = 0, index2 = 0;
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
                                      
                                      
                                      
                                      
