class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0; //starting position
        int end=0;  //ending position
        int max_len=0; //the length of the max substring
        for(int i=0;i<len;i++)
        {
            int len1 = expendaroundcenter(s, i, i); //when the length is odd
            int len2 = expendaroundcenter(s, i, i+1);//when the length is even
            max_len=max(max(len1,len2),max_len);
            if(max_len>end-start+1)
            {
                start=i-(max_len-1)/2;
                end = i +max_len/2;
            }
        }
        return s.substr(start,max_len);
    }
private:
    int expendaroundcenter(string s,int left, int right)
    {
        int L = left;
        int R = right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
};