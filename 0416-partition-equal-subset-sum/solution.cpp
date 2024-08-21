class Solution {
public:
    vector<vector<int>> dp;
    
    bool f(int i, int currentSum, int totalSum, vector<int>& nums) {
        if (currentSum * 2 == totalSum) return true;
        if (i >= nums.size() || currentSum * 2 > totalSum) return false;
        
        if (dp[i][currentSum] != -1) return dp[i][currentSum];
        
        // Include nums[i]
        bool include = f(i + 1, currentSum + nums[i], totalSum, nums);
        
        // Exclude nums[i]
        bool exclude = f(i + 1, currentSum, totalSum, nums);
        
        dp[i][currentSum] = include || exclude;
        return dp[i][currentSum];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        
        dp = vector<vector<int>>(nums.size(), vector<int>(totalSum / 2 + 1, -1));
        return f(0, 0, totalSum, nums);
    }
};

