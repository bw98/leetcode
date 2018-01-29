//Runtime: 6 ms

#include<unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {             
        unordered_map<int,int> um;
        vector<int> res(2);
        int i;
        int n = nums.size();
        for (i = 0; i < n; ++i) {
            if (um.find(target - nums[i]) != um.end()) {
                res[0] = um[target - nums[i]];
                res[1] = i; 
                return res;  
            }
            else {
                um[nums[i]] = i;          
            }            
        }
        um.clear();
    }   
};

