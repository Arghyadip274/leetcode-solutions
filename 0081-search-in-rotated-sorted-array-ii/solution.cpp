class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while (l<=r){
            int mid =l+(r-l)/2;
            if (nums[mid]==target) return 1;
            if(nums[l]==nums[mid] and nums[r]==nums[mid]) {
                l++;
                r--;
            }
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target and nums[mid]>target) r=mid-1;
                else l=mid+1;
            }
            else {
                if(nums[mid]<target and nums[r]>=target) l=mid+1;
                else r=mid-1;
            }
        }
        return 0;
    }
};
