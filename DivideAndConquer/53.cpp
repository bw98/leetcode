#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = findMaxSubarray (nums, 0, nums.size()-1);
        nums.clear();
        vector<int>().swap(nums);
        return res;
    }
private:
    int findMaxSubarray (vector<int>& nums, const int& low, const int& high) {        
        if (low == high) return nums[low]; //base case: only one element
        else { 
            int mid =low + (high-low)/2;
            int left_sum = findMaxSubarray (nums, low, mid);
            int right_sum = findMaxSubarray (nums, mid + 1, high);
            int cross_sum = findMaxCrossingSubarray (nums, low, high);
            // chose the max case of them
            if (left_sum >= right_sum && left_sum >= cross_sum)
                return left_sum;
            else if (right_sum >= left_sum && right_sum >= cross_sum)
                return right_sum;
            else 
                return cross_sum;
        }
    }
    
    int findMaxCrossingSubarray (vector<int>& nums, const int& low, const int& high) {
        int left_sum = INT_MIN;
        int sum = 0;
        int mid = low + (high-low)/2;
        for (int i = mid; i >= low; --i) {
            sum += nums[i];
            if (left_sum < sum) 
                left_sum = sum;
        }
        
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid+1; i <= high; ++i) {
            sum += nums[i];
            if (right_sum < sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }
};

int main(void) {
    Solution *sample = new Solution();
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4}; //here input test case
    int res = sample->maxSubArray(vec);
    cout << res << endl;
    return 0;
}
