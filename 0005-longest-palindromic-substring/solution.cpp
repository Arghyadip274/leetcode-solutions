class Solution {
public:
    bool f(int i, int j, string &s,vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=0;
        return dp[i][j]=f(i+1, j-1,s,dp);
    }

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int start=0;
        int len =1;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if(f(i,j,s,dp)){
                    if(j-i+1>len){
                        len=j-i+1;
                        start =i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
