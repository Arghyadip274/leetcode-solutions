class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minSum=nums[0]+nums[1]+nums[2];
        for (int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while (l<r){
                int newSum=nums[i]+nums[l]+nums[r];
                if(abs(minSum-target)>abs(newSum-target)) minSum=newSum;
                if(newSum>target) r--;
                else if(newSum<target)l++;
                else return target;
            }
        }
        return minSum;
    }
};
