class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> hash;
        // sort(nums.begin(), nums.end());
        for (int i=0;i<n;i++){
            hash.insert(nums[i]);
        }
        int count=1;
        for (auto i:hash){
           if(hash.count(i-1)) continue;
            int cur= i;
            int count=1;
            while(hash.count(cur+1)){
                cur++;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
