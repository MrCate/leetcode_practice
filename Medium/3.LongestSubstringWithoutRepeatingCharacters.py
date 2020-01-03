class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = len(s)  #获取字符串长度
        start = 0
        end = 0  #创建两个指针
        max_len = 0
        current_len = 0
        while(end<l):
            while s[end] in s[start:end]:
                start += 1
            current_len = end - start + 1
            if(current_len > max_len):
                max_len = current_len
            end += 1
        return max_len