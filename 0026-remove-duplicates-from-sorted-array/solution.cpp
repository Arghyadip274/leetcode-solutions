class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
        ans=nums;
        for (int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for (int i=0;i<nums.size();i++){
            if(hash[nums[i]]>1) {
                ans[i]=101;
                hash[nums[i]]--;
            }
        }
        erase(ans,101);
        nums=ans;
        return hash.size();
    }
};
