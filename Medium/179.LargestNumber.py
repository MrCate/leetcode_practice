class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        '''
        map(str,nums)是将nums转成str类型，再对nums降序排序，排序规则是取首位最大的数，如果首位都一样大，找第二位大的，以此类推。。。
        '''
        if largest_num[0] == '0':
            return '0'
        else:
            return largest_num
        #return '0' if largest_num[0]=='0' else largest_num
        #3 30 34 5 9