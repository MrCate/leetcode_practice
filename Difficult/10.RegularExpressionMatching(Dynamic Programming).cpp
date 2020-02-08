class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if(p.empty())   return s.empty();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1,false));
        dp[0][0]=true;
        for(int i=1;i<=np;i++){
            if(i-2>=0 && p[i-1] =='*'&& p[i-2])
                dp[0][i] = dp[0][i-2];
        }
        for(int i=1;i<=ns;i++){
            for(int j=1;j<=np;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1]=='*')
                {
                    bool zero, one;
                    if(j-2>=0){
                        zero = dp[i][j-2];
                        one = (p[j-2]==s[i-1]||p[j-2]=='.') && dp[i-1][j];
                        dp[i][j] = zero||one;
                    }
                }
            }
        }
        return dp[ns][np];
    }
};