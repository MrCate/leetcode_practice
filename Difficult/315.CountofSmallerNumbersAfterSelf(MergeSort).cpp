class Solution {
public:
    vector<int> res;
    vector<int> countSmaller(vector<int>& vec) {
        if(vec.empty())
            return {};
        vector<pair<int,int>> nums;
        for(int i=0;i<vec.size();i++)
            nums.emplace_back(vec[i],i);
        res = vector<int>(vec.size(),0);
        merge_sort(nums,0,(int)nums.size()-1);
        return res;
    }
    void merge_sort(vector<pair<int,int>>& nums, int left, int right){
        if(left<right){
            int mid = (left+right)/2;
            merge_sort(nums,left,mid);
            merge_sort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    void merge(vector<pair<int,int>>& nums,int left,int mid, int right){
        int i=left,j=mid+1,k=left;
        vector<pair<int,int>> sort_nums;
        while(i<=mid&& j<=right){
            if(nums[i].first<=nums[j].first){
                res[nums[i].second]+= j-mid-1;
                sort_nums.push_back(nums[i++]);
            }
            else if(nums[i].first >nums[j].first){
                sort_nums.push_back(nums[j++]);
            }
        }
        while (i <= mid){
            res[nums[i].second] += j - mid - 1;
            sort_nums.push_back(nums[i++]);
        }
        while (j <= right){
            sort_nums.push_back(nums[j++]);
        }
        for (int m = 0, n = left; m < sort_nums.size(); m++, n++){
            nums[n] = sort_nums[m];
        }      
    }
};