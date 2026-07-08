class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void f(int start, int target,vector<int>&nums){
        if (target==0 ){
            ans.push_back(path);
            return;
        }
        if(target<0) return;
        for (int i=start;i<nums.size();i++){
            if(i>start and nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            f(i+1,target-nums[i],nums);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        f(0,target,nums);
        // vector<vector<int>> res(ans.begin(), ans.end());
        return ans;      
    }
};
