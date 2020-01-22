class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            int l_max = 0,r_max = 0;
            for(int j = i;j<n;j++)
                r_max = max(r_max,height[j]);
            for(int j = i;j>=0;j--)
                l_max = max(l_max,height[j]);
            ans += min(l_max,r_max) - height[i];
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int n = height.size();
        int ans = 0;
        vector<int> l_max(n);
        vector<int> r_max(n);
        l_max[0] = height[0];
        r_max[n-1] = height[n-1];
        for(int i=1;i<n;i++)
            l_max[i] = max(l_max[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            r_max[i] = max(r_max[i+1],height[i]);
        for(int i=0;i<n;i++)
            ans += min(l_max[i], r_max[i])-height[i];
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int n = height.size();
        int ans = 0;
        int left=0,right=n-1;
        int l_max = height[0];
        int r_max = height[n-1];
        while(left<=right){
            l_max = max(l_max,height[left]);
            r_max = max(r_max,height[right]);
            if(l_max<r_max)
            {
                ans += l_max-height[left];
                left++;
            }
            else{
                ans += r_max-height[right];
                right--;
            }    
        }  
        return ans;
    }
};