class Solution {
public:
    string longestPalindrome(string s) {
        string cur_str;
        string max_str;
        int i;
        int j;
        if(s.length()==1)
            return s;
        if(s.length()==2)
        {
            if(s[0]==s[1])
                return s;
        }
        for(i = 0;i<s.length();i++)
        {
            for(j=1;j<s.length()-i+1;j++)
            {
                cur_str = s.substr(i,j);
                int start = i;
                int end = i+j-1;
                while(valid(cur_str,start,end)==true)
                {
                    if(cur_str.length()>max_str.length())
                        max_str = cur_str;
                }
            }
        }
        return max_str;
    }
    bool valid(string s, int left, int right){
        while(left<right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;            
        }
        return true;
    }
};