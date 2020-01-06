class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int dp = nums[0];
        int result = nums[0];
        for(int i=1;i<nums.size();i++)
        {
                dp=max(nums[i],dp+nums[i]);
                result = max(result, dp);
        }
        return result;
    }
};