class Solution {
public:
    int f(int i, int j, string word1, string word2,vector<vector<int>> &dp){
        //basecase
        if (i>=word1.size()) return word2.size()-j;
        if (j>=word2.size()) return word1.size()-i;
        //pruning
        //cache check
        if(dp[i][j]!=-1) return dp[i][j];
        //transition
        int take=1e9,notTake=1e9;
        if(word1[i]==word2[j]) take=f(i+1,j+1,word1,word2,dp);
        notTake=1+min(f(i+1,j,word1,word2,dp),f(i,j+1,word1,word2,dp));

        //save and return
        return dp[i][j]=min(take,notTake);

    }
    int minDistance(string word1, string word2) {
        int n,m;
        n=word1.size();
        m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,word1,word2,dp);
    }
};
