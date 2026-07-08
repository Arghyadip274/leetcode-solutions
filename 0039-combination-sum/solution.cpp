class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int sum=0;
    void f(int start,int target, vector<int> &nums){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if (target<0) return;
        for (int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            f(i,target-nums[i],nums);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0,target,candidates);
        return ans;
    }
};
