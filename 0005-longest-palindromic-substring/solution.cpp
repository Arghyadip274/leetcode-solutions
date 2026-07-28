class Solution {
public:
    vector<vector<int>> dp;
    bool f(int i , int j, string &s){
        if(i>=j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]= 0;
        return dp[i][j]=f(i+1, j-1,s);
    }



    string longestPalindrome(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        int start=0;
        int len=1;
        for (int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(f(i,j,s)){
                    if(j-i+1>len){
                        len=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};
