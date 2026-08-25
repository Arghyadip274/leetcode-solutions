class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        int l=0;
        int r=n-1;
        int test=-1;
        while (l<=r){
            int mid =l+(r-l)/2;
            if (nums[mid]==target){
                test=mid;
                r=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1; 
        }
        ans.push_back(test);
        l=0;
        r=n-1;
        test=-1;
        while (l<=r){
            int mid =l+(r-l)/2;
            if (nums[mid]==target){
                test=mid;
                l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1; 
        }
        ans.push_back(test);
        return ans;
    }
};
