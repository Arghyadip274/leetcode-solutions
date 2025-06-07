

class Solution {
public:
    bool f(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        //basecase
        if (target==0) return 1;
        if (i >= nums.size() or target < 0) return 0;
        if (dp[i][target]!=-1) return dp[i][target];
        int take,notTake;
        if(i>=0 and i<nums.size()){
            if(target>=0){
                take=f(i+1,target-nums[i],nums,dp);
            }
            notTake=f(i+1,target,nums,dp);

        }

        return dp[i][target]=take || notTake;


    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(sum/2 +1,-1));
        return f(0,sum/2,nums,dp)>0;


        
        
        
    }
};
