class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<=2 ||nums[0]>0||nums[nums.size()-1]<0)
            return ans;
        for(int i=0; i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target = 0-nums[i];
            int k = i+1;
            int m = nums.size() -1;
            while(k<m)
            {
                if(nums[k] > target)
                    break;
                if((k>i+1 && nums[k] == nums[k-1])||nums[k]+nums[m]<target)
                    k++;
                else if((m<nums.size()-1 && nums[m]==nums[m+1]) || nums[k]+nums[m]>target)
                    m--;
                else{
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[k]);
                    vec.push_back(nums[m]);
                    ans.push_back(vec);
                    k++;
                }
            }
        }
        return ans;
    }
};