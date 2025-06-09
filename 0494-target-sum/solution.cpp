class Solution {
public:
    int f(int i, int target, vector<int>& nums, vector<vector<int>>& dp, int offset, int total) {
        if (i == nums.size()) return target == 0;

        // Prevent out-of-bounds access to dp
        if (target + offset < 0 || target + offset > 2 * total) return 0;

        if (dp[i][target + offset] != -1) 
            return dp[i][target + offset];

        int plus = f(i + 1, target - nums[i], nums, dp, offset, total);
        int minus = f(i + 1, target + nums[i], nums, dp, offset, total);

        return dp[i][target + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        return f(0, target, nums, dp, total, total);
    }
};

