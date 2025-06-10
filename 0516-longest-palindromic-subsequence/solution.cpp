class Solution {
public:
    int f(int i, int j,string s, string r,vector<vector<int>>&dp){
        //basecase
        if(i==s.size()||j==r.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        if (s[i]==r[j]) take=1+f(i+1,j+1,s,r,dp);
        notTake=max(f(i+1,j,s,r,dp),f(i,j+1,s,r,dp));
        return dp[i][j]=max(take,notTake);

    }


    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size();
        vector<vector<int>> dp(s.size()+1,vector<int>(r.size()+1,0));
        //return f(0,0,s,r,dp);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
};
