class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int> hash;
        vector<int>result;

        for (int i=0;i<nums.size();i++){ 
            if (nums[i]!=target-nums[i]){
                auto it=find(nums.begin(),nums.end(),target-nums[i]);
                if (it!=nums.end()){
                    result.push_back(i);
                    result.push_back(it-nums.begin());
                    break;
                }
            }
            else{
                auto it=nums.begin();
                while ((it = find(it, nums.end(), target-nums[i])) != nums.end()){
                    if (it-nums.begin()!=i){
                        result.push_back(i);
                        result.push_back(it-nums.begin());
                        break;
                    }
                    it++;
                }
                sort(result.begin(),result.end());
                auto u=unique(result.begin(),result.end());
                result.resize(distance(result.begin(),u));           
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
