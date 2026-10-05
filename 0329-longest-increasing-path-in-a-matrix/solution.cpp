class Solution {
public:
    int n,m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isValid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    vector<vector<int>>dp;
    int solve(int i, int j,int prev, vector<vector<int>>&g){
        if(!isValid(i,j) or g[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for (int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isValid(x,y)){
                dp[i][j]=max(dp[i][j],1+solve(x,y,g[i][j],g));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.assign(n,vector<int>(m,-1));
        int maxPath=1;
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxPath=max(maxPath,solve(i,j,-1,matrix));
            }
        }
        return maxPath;
    }
};
