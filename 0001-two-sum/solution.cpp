class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int> hash;
        while (n--){
            hash[nums[n]]=n;
        }
        for (int i=0;i<nums.size();i++){
            int need = target - nums[i];
            if(hash.count(need)) {
                if (hash[need]==i) continue;
                else return {i, hash[need]};
            }
            else continue;
        }
        return {-1};
    }
};
