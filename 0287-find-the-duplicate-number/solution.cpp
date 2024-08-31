class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (auto i:nums){
            hash[i]++;
        }
        int res=-1;
        for(auto &it:hash){
            if (it.second >1) {
                res=it.first;
                break;
            }
        }
        return res;
    }
};
