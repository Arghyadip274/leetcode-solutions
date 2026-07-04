class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n=nums.size();
        for (int i=0;i<n;i++){
            hash[nums[i]]=i+1;
        }
        vector<int> ans;

        for (int i=0;i<n;i++){
            int need=target-nums[i];
            if(hash.count(need)){
                ans.push_back(i+1);
                ans.push_back(hash[need]);
                break;
            }
        }
        return ans;
    }
};
