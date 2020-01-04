class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        vector<int> temp(2, 0);
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    temp[0]=i;
                    temp[1]=j;
                }
            }
        }
        return temp;
    }
};