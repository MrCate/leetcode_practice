class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int ans = INT_MAX;
        for(int coin : coins){
            if(amount - coin <0)
                continue;
            int subProb = coinChange(coins, amount - coin);
            if(subProb == -1)
                continue;
            ans = min(ans, subProb+1);
        }
        return ans == INT_MAX ? -1: ans;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -2);
        return helper(coins, amount, memo);
    }
    int helper(vector<int>& coins, int amount, vector<int>& memo){
        if(amount == 0)
            return 0;
        if(memo[amount] != -2)
            return memo[amount];
        int ans = INT_MAX;
        for(int coin:coins){
            if(amount - coin <0)
                continue;
            int subProb = helper(coins, amount-coin, memo);
            if(subProb == -1)
                continue;
            ans = min(ans, subProb+1);
        }
        memo[amount]=(ans==INT_MAX)?-1:ans;
        return memo[amount];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(coin<=i)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount]>amount? -1:dp[amount];
    }

};