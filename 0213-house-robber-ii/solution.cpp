class Solution {
public:
    int f(int i, int end, vector<int> &nums, vector<int> &dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];

        // Rob this house and move to i+2
        int rob = nums[i] + f(i + 2, end, nums, dp);
        // Skip this house and move to i+1
        int skip = f(i + 1, end, nums, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Rob from house 0 to n-2 (exclude last)
        int case1 = f(0, n - 2, nums, dp1);
        // Rob from house 1 to n-1 (exclude first)
        int case2 = f(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};

