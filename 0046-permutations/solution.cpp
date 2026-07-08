class Solution {
public:
    void f(vector<int> &nums,vector<int> &path, vector<vector<int>> &ans, unordered_map<int,bool>&used ){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if(used[nums[i]]) continue;
            used[nums[i]]=1;
            path.push_back(nums[i]);
            f(nums,path,ans,used);
            used[nums[i]]=0;
            path.pop_back();
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int>path;
        unordered_map<int,bool> used;
        f(nums,path,ans,used);
        return ans;
    }
};
