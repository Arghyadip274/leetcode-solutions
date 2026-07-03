// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> prefix;
//         vector<int> ans;
//         int n=nums.size();
//         int prod=1;
//         prefix.push_back(nums[i]);
//         for (int i=1;i<n;i++){
//             prefix.push_back(prefix[i-1]+nums[i]);
//         }
//         for (int i=1;i<n;i++}{
//             if(prefix[i]==prefix[i-1]) {
//                 ans.push_back()
//             }
//         }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1;
        int n=nums.size();
        int count0=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]!=0)prod*=nums[i];
            else{
                count0++;
            }
        }
        if(count0>1) {
            for (int i=0;i<n;i++){
                ans.push_back(0);
            }
        }
        else if(count0==1){
            for (int i=0;i<nums.size();i++){
                if(nums[i]==0) ans.push_back(prod);
                else ans.push_back(0);
            }
        }
        else{
            for (int i=0;i<nums.size();i++){
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};
