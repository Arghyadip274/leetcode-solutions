class Solution {
public:
    int f(int i,int j,int m, int n,vector<vector<int>> &dp){
        //basecase
        if(i==m-1 and j==n-1){
            return 1;
        }
        if (dp[i][j]!=-1) return dp[i][j];

        int down = 0, right = 0;
        if (i+1<=m-1){
            down = f(i+1,j,m,n,dp);
        }
        if (j+1<=n-1){
            right = f(i,j+1,m,n,dp);
        }

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,dp);
    }
};

