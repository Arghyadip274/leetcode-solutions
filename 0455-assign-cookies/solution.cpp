class Solution {
public:
    // int f(int i,int j,vector<int> &g,vector<int>&s,vector<vector<int>>&dp){
    //     //basecase
    //     if(i>=g.size() or j>=s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int give=INT_MIN,notGive=INT_MIN;
    //     if (s[j]>=g[i]) give=1+f(i+1,j+1,g,s,dp);
    //     notGive=f(i,j+1,g,s,dp);

    //     return dp[i][j]=max(give,notGive);
    // }

    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(),g.end());
    //     sort(s.begin(),s.end());
    //     vector<vector<int>> dp(g.size(),vector<int>(s.size(),-1));
    //     return f(0,0,g,s,dp);
    // }

    int findContentChildren(vector<int>& g, vector<int>& s){
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int i = 0, j = 0, count = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            count++;
            i++;
        }
        j++;
    }
    return count;
    }
};
