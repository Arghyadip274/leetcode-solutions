class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        vector<int> ans;
        int temp=-1;
        while (l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                temp=mid;
                r=mid-1;
            }
            else if (nums[mid]> target) {
                r=mid-1;
            }
            else l=mid+1;
        }
        ans.push_back(temp);
        temp=-1;
        l=0;
        r=n-1;
        while (l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                temp=mid;
                l=mid+1;
            }
            else if (nums[mid]> target) {
                r=mid-1;
            }
            else l=mid+1;
        }
        ans.push_back(temp);
        return ans;
    }
};
