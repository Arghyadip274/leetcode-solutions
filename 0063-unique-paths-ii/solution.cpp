class Solution {
public:
    int isValid(int i, int j, vector<vector<int>> &obstacleGrid){
    if (i < obstacleGrid.size() && j < obstacleGrid[0].size() && obstacleGrid[i][j] == 0)
        return 1;
    return 0;
}


    int f(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp){
        //basecase
        if(i==obstacleGrid.size()-1 and j==obstacleGrid[0].size()-1){
            return 1;
        }
        if (dp[i][j]!=-1) return dp[i][j];

        int down = 0, right = 0;
        if (isValid(i+1,j,obstacleGrid)){
            down = f(i+1,j,obstacleGrid,dp);
        }
        if (isValid(i,j+1,obstacleGrid)){
            right = f(i,j+1,obstacleGrid,dp);
        }

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        return f(0,0,obstacleGrid,dp);
    }
};
