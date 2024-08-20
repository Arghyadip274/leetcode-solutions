class Solution {
public:
    int f(vector<int> &nums,int n,int curr,int prev,vector<vector<int>>&dp){
        //pruning
        //basecase
        if(curr==n) return 0;
        //cache check
        if (dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        //transition
        int ans=0;
        int take=INT_MIN,notTake=INT_MIN;
        notTake=0+f(nums,n,curr+1,prev,dp);
        if (prev==-1||nums[curr]>nums[prev]){
            take=1+f(nums,n,curr+1,curr,dp);
        }
        //save and return
        ans=max(take,notTake);
        return dp[curr][prev+1]=ans;
    }
    
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,n,0,-1,dp);
    }      
};
    // int f(int ind, int prev,int n, vector<int> &nums, vector <vector<int>>&dp){
    //     if (ind==n) return 0;
    //     if (dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int len=f(ind+1,prev, n,nums,dp);
    //     if (prev==-1|| nums[ind]>nums[prev]){
    //         len=max(len,1+ f(ind+1,ind,n,nums,dp));
    //     }
    //     return dp[ind][prev+1]=len;
    // }
