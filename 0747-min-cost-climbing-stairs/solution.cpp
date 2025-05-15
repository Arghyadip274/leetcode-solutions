class Solution {
public:
    
    int f(int i,vector<int>&cost,vector<int>&dp){
        //basecase
        if (i==cost.size()){
            return 0;
        }
        if (dp[i]!=-1) return dp[i];
        int j1,j2;
        j1=cost[i]+f(i+1,cost,dp);
        j2=1e9;
        if (i+2<cost.size()+1){
            j2=cost[i]+f(i+2,cost,dp);
        }
        return dp[i]=min(j1,j2);


    }

    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(f(0,cost,dp),f(1,cost,dp));
    }
};
