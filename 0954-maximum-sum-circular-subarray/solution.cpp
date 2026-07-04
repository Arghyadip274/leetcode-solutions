class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int curMax=0;
        int curMin=0;
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int tot=0;
        for (int i=0;i<n;i++){
            curMax=max(nums[i], curMax+nums[i]);
            curMin=min(nums[i], curMin +nums[i]);
            maxSum=max(maxSum, curMax);
            minSum=min(minSum, curMin);
            tot+=nums[i];
        }
        if(maxSum<0) return maxSum;
        return max(maxSum, tot-minSum);

    }
};
