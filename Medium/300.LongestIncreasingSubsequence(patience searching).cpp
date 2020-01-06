class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> top(nums.size(), 0);//record each pile's min card
        int piles=0; //record the number of piles which is the answer
        for(int i =0;i<nums.size();i++)
        {
            int poker = nums[i];
            //binary searching
            int left = 0;
            int right = piles;
            while(left<right)
            {
                int mid = (left+right)/2;
                if(top[mid]>=poker)
                    right = mid;
                else
                    left = mid + 1;
            }
            if(left == piles)
                piles++;
            top[left] = poker;
        }
        return piles;
    }
};