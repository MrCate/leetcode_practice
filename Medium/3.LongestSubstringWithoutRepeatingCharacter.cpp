class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int cur_len=0;
        int start=0;
        int end=0; 
        while(end<s.length())
        {
            while(s.substr(start, end).find(s[end]) != string::npos)
            {
                start += 1;
            }
            cur_len = end - start + 1;
            if(cur_len>max_len){
                max_len = cur_len;
            }
            end += 1;
        }
        return max_len;
    }
};