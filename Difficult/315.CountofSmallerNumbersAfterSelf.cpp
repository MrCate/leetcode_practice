class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int count = 0;
            for(int j=i+1;j<nums.size();j++){             
                if(nums[i]>nums[j])
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};