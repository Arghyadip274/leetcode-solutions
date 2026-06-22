class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int> ans;
        while (l<=r){
            int mid =l+(r-l)/2;
            if (nums[mid]== target){
                if (mid==0 or nums[mid]!= nums[mid-1]) {
                    ans.push_back(mid);
                    break;
                }

                else r=mid-1;
            }
            else if (nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        l=0;
        r=n-1;
        while (l<=r){
            int mid =l+(r-l)/2;
            if (nums[mid]== target){
                if (mid==n-1 or nums[mid]!= nums[mid+1]) {
                    ans.push_back(mid);
                    break;
                }
                else l=mid+1;
            }
            else if (nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        if (ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
