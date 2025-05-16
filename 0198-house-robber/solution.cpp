class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp) {
        // basecase
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int r2, r3;
        r2 = -1e9;
        r3 = -1e9;
        if (i + 2 <= nums.size() - 1) {
            r2 = nums[i] + f(i + 2, nums, dp);
        } else {
            r2 = nums[i]; // valid terminal jump
        }
        if (i + 3 <= nums.size() - 1) {
            r3 = nums[i] + f(i + 3, nums, dp);
        } else if (i + 3 == nums.size()) {
            r3 = nums[i]; // exact end
        }

        return dp[i] = max(r2, r3);
    }

    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(f(0, nums, dp1), f(1, nums, dp2));
    }
};

