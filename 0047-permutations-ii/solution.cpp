class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    void f(vector<int> nums){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if (i>0 and nums[i]==nums[i-1] and !used[i-1])continue;
            if(used[i]==0){
                used[i]=1;
                path.push_back(nums[i]);
                f(nums);
                used[i]=0;
                path.pop_back();
            }
            else continue;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used.assign(nums.size(),0);
        f(nums);
        return ans;
    }
};
