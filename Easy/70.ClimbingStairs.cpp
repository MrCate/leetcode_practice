class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        int p=1,q=2,temp=0;
        for(int i=3;i<=n;i++){
            temp = q;
            q = p+q;
            p = temp;          
        }
        return q;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else
            return climbStairs(n-1) +climbStairs(n-2);
    }
};