// #include <bits/stdc++.h>
class Solution {
public:
    int f(string &word1, string &word2,int n,int m,vector<vector<int>> &dp){
        if (n<0) return m+1;
        if (m<0) return n+1;
        if (dp[n][m]!=-1) return dp[n][m];
        if (word1[n]==word2[m]) return dp[n][m]=f(word1,word2,n-1,m-1,dp);
        return dp[n][m]=1 +min(f(word1,word2,n-1,m-1,dp),min(f(word1,word2,n-1,m,dp),f(word1,word2,n,m-1,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(word1,word2,n-1,m-1,dp) ;
    }
};
