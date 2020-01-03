class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int i,j,k;
        vector<int> temp(length1+length2, 0);
        for(i=0,j=0,k=0;i<length1&&j<length2;k++)
        {
            if(nums1[i]<nums2[j])
            {
                temp[k] = nums1[i];
                i++;
            }
            else
            {
                temp[k] = nums2[j];
                j++;
            }
        }
        while(i<length1)        
            temp[k++]=nums1[i++];
        while(j<length2)
            temp[k++]=nums2[j++]; 
        if((length1+length2)%2 ==1)      
            return temp[(length1+length2)/2];    
        else
            return (temp[(length1+length2)/2]+temp[(length1+length2)/2-1])/2.0;
    }
}; 