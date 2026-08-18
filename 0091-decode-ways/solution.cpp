class Solution {
public:
    int f(int i, string s, vector<int> &dp){
        if (i<0) return 1;
        if (dp[i]!=-1) return dp[i];
        int take1=0, take2=0;
        if( s[i]!='0') take1=f(i-1,s, dp);
        if(i>=1 and s[i-1]!='0') {
            int val=(s[i-1]-'0')*10+ (s[i]-'0');
            if (val<=26)take2=f(i-2,s,dp);
        }
        return dp[i]=take1+take2;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return f(s.size()-1,s,dp);
    }
};
