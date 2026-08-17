class Solution {
public:
    int f(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp){
        if (i==0 and j==0) return g[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=1e9, left=1e9;
        if(i>0) up=g[i][j]+f(i-1,j,g,dp);
        if(j>0) left=g[i][j]+f(i, j-1,g,dp);
        return dp[i][j]=min(up,left);
    }


    int minPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,g,dp);   
    }
};
