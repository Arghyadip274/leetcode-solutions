class Solution {
public:
    int f(int i ,int j, vector<vector<int>> &triangle,vector<vector<int>>&dp){
        //base case
        if (i==triangle.size()-1){
            return triangle[i][j];
        }
        if (dp[i][j]!=-1) return dp[i][j];
        int adj1=1e9,adj2=1e9;
        adj1=triangle[i][j]+f(i+1,j,triangle,dp);
        adj2=triangle[i][j]+f(i+1,j+1,triangle,dp);
        

        return dp[i][j]=min(adj1,adj2);



    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};
