class Solution {
public:
    bool rec(vector<int>& stones, int i, int j, vector<vector<int>>& dp) {
        int n = stones.size();     

        // base case
        if (i == n - 1) return true;

        if (dp[i][j] != -1) return dp[i][j];

        for (int ind = i + 1; ind < n; ind++) {
            int gap = stones[ind] - stones[i];
            if (gap > j + 1) break; // optimization to exit early

            for (int k = -1; k <= 1; ++k) {
                int nextJump = j + k;
                if (nextJump <= 0) continue;
                if (gap == nextJump) {
                    if (rec(stones, ind, nextJump, dp)) {
                        return dp[i][j] = true;
                    }
                }
            }
        }

        return dp[i][j] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(stones, 1, 1, dp); // start at index 1 with jump of 1
    }
};

