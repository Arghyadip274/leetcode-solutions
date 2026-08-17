class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If our current index is beyond our furthest reach, we are stuck.
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest we can reach from this index.
            maxReach = max(maxReach, i + nums[i]);
            
            // Early exit: if we can already reach or pass the end, we're done.
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
