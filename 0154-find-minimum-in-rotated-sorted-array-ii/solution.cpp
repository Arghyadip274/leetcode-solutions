class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=1e9;
        while (l<=r){
            int mid=(l+r)/2;
            if (nums[l]==nums[mid] and nums[mid]==nums[r]){
                l++;
                r--;
            }
            else if(nums[mid]<=nums[r]){
                r=mid;
            }
            else l=mid+1;
            ans =min(ans, nums[mid]);

        }
        return ans;
    }
};

