class Solution {
public:
    int f(int i,int j,string s,string r,vector<vector<int>> &dp){
        //basecase
        if(i>=s.size() or j>=r.size()) return 0;
        //cache check
        if(dp[i][j]!=-1) return dp[i][j];
        //transition 
        int leave=0,insert=0;
        if(s[i]==r[j]) leave=1+f(i+1,j+1,s,r,dp);
        insert=max(f(i+1,j,s,r,dp),f(i,j+1,s,r,dp));
        //saveandreturn
        return dp[i][j]=max(leave,insert);
    }
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
            }

        }
        return n-dp[n][n];

    }
};
