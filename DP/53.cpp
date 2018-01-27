class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp, sum;
        dp = nums[0];
        sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp > 0) {
                dp += nums[i];
            }
            else dp = nums[i];
            if (dp > sum)
                sum = dp;
        }
        return sum;
    }
};
