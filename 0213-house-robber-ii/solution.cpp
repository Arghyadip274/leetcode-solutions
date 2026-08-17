class Solution {
public:
    int f(int start, int end, vector<int>&nums, vector<int>&dp){
        if(end<start) return 0;
        if(dp[end]!=-1) return dp[end];
        int take=nums[end]+f(start,end-2,nums,dp);
        int notTake=f(start,end-1, nums,dp);
        return dp[end]=max(take,notTake);
    }


    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(f(0,n-2,nums,dp1),f(1,n-1,nums,dp2));
    }
};

