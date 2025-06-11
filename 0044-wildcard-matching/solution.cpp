class Solution {
public:
    bool f(int i,int j,string s,string p,vector<vector<int>>&dp){
        //basecase
        if(j>=p.size() and i>=s.size() ) return 1;
        if(i<s.size() and j>=p.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match=0;
        if(p[j]=='*') {
            bool take0=f(i,j+1,s,p,dp);
            bool take1=(i < s.size()) && f(i+1,j,s,p,dp);
            match=take0||take1;
        }
        else {
            if (i < s.size() && (s[i] == p[j] || p[j] == '?')) {
                match = f(i + 1, j + 1, s, p, dp);
            } else {
                match = false;
            }
        }
        return dp[i][j]=match;
    }
    bool isMatch(string s, string p) {
        int n,m;
        n=s.size();
        m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
            else break;
        }
        for (int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*') {
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
                else if( (s[i-1] == p[j-1] || p[j-1] == '?')) {
                    dp[i][j] = dp[i-1][j-1];
                }
                
            }
        }
        return dp[n][m];
    }
};
