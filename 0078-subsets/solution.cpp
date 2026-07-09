class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void f(int start, vector<int> &nums){
        ans.push_back(path);
        for (int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            f(i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(0,nums);
        return ans;
    }
};
