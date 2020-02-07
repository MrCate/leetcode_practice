class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        if(nums.size()==1)
            return 1;
        for(int i=1;i<nums.size();i++){
            dp[0] = 1;
            if(nums[i]==nums[i-1]+1)
                dp[i] = dp[i-1]+1;
            else if(nums[i] == nums[i-1])
                dp[i] = dp[i-1];
            else
                dp[i] = 1;
        }
        auto maxPosition = max_element(dp.begin(), dp.end());
        return *maxPosition;
    }
};