class Solution {
public:
    int f(int i,int j,int m, int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        //basecase
        if(i==m-1 and j==n-1){
            return grid[i][j];
        }
        if (dp[i][j]!=-1) return dp[i][j];

        int down = 1e9, right = 1e9;
        if (i+1<=m-1){
            down = grid[i][j]+f(i+1,j,m,n,grid,dp);
        }
        if (j+1<=n-1){
            right = grid[i][j]+f(i,j+1,m,n,grid,dp);
        }
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,grid,dp);
    }
};
