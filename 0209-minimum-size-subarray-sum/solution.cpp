class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int head=-1,tail=0;
        int ans=n+1;
        int sum=0;
        while(tail<n){
            while(head+1<n and sum<target){
                head++;
                sum+=nums[head];
            }
            if (sum>=target){
                ans=min(ans,head-tail+1);
            }
            sum-=nums[tail];
            tail++;
            if (tail>head){
                head=tail-1;
            }

        }
        return (ans==n+1)?0:ans;
    }
};
