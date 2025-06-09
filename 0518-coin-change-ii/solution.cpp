class Solution {
public:
    int f(int i,int amount,vector<int> &coins, vector<vector<int>>&dp){
        //basecase
        if (amount==0) return 1;
        if (i>=coins.size() or amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0,notTake=0;
        if (i<coins.size()){
            take=f(i,amount-coins[i],coins,dp);
            notTake=f(i+1,amount,coins,dp);
        }
        return dp[i][amount]=take+notTake;
    }


    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);
    }
};
