class Solution {
public:
    int f(string &text1, string &text2,int l1, int l2,vector<vector<int>>&dp){
        if (l1<0||l2<0) return 0;
        if (dp[l1][l2]!=-1) return dp[l1][l2];
        if (text1[l1]==text2[l2]){
            return dp[l1][l2]=1+f(text1,text2,l1-1,l2-1,dp);
        }
        return dp[l1][l2]=0+max(f(text1,text2,l1-1,l2,dp),f(text1,text2,l1,l2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1= text1.length();
        int l2= text2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return f(text1,text2,l1-1,l2-1,dp);
    }
};
