class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for (int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if (hash.count(rem) and i!=hash[rem]){
                ans={i,hash[rem]};
                break;
            } 
            else continue;
        }
        return ans;
    }
};
