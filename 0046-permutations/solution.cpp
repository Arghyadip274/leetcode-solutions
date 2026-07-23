class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_map<int,bool> used;
    void f(vector<int> &nums){
        if (path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if(used[nums[i]])continue;
            used[nums[i]]=1;
            path.push_back(nums[i]);
            f(nums);
            path.pop_back();
            used[nums[i]]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums);
        return ans;
    }
};
