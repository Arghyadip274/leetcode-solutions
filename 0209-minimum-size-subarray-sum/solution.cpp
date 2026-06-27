class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head=-1;
        int tail=0;
        int sum=0;
        int n=nums.size();
        int ans=1e9;
        while (tail<n){
            while (head+1 <n and sum<target){
                head++;
                sum+=nums[head];
            }
            if (sum>=target){
                ans=min(ans,head-tail+1);
            }
            sum-=nums[tail];
            tail++;
            if(head<tail){
                head=tail-1;
            }
        }
        return (ans>n)?0:ans;
    }
};
