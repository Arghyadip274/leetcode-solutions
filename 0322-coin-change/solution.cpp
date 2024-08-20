class Solution {
public:
    int f(int level,int amount,vector<int>&coins,vector<vector<int>>&dp){
        //pruning
        //basecase
        if (level == coins.size()-1) {
            if (amount % coins[level] == 0) {
                return amount/ coins[level];
            }
            return INT_MAX-1;
        }
        //cache check
        if (dp[level][amount]!=-1) return dp[level][amount];
        //transition
        int ans=0;
        int take=INT_MAX,notTake;
        if (coins[level]<=amount){
            take=1+f(level,amount-coins[level],coins,dp);
        }
        notTake=f(level+1,amount,coins,dp);
        //save and return
        ans=min(take,notTake);
        return dp[level][amount]=ans;
    }


    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans=f(0,amount,coins,dp);
        if (ans==INT_MAX-1 )return -1;
        else return ans;
    }
};
