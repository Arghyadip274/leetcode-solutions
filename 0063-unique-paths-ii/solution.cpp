class Solution {
public:
    int f (int i, int j ,vector<vector<int>> &g, vector<vector<int>> &dp){
        if(i== 0 and j==0) return 1;
        if (dp[i][j]!=-1) return dp[i][j];
        int up=0, left=0;
        if (i>0 and g[i][j]!=1) up=f(i-1,j,g,dp);
        if(j>0 and g[i][j]!=1) left=f(i,j-1,g,dp);
        return dp[i][j]=up+left;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        if(g[0][0]==1 or g[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,g,dp);
    }
};
