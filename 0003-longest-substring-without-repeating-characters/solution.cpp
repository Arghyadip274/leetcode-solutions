class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> hash;
        int head=-1,tail=0;
        int ans=0;
        while(tail<n){
            while(head+1<n and hash[s[head+1]]==0){
                head++;
                hash[s[head]]++;

            }
            ans=max(ans,head-tail+1);
            hash[s[tail]]--;
            tail++;
            if (tail>head){
                head=tail-1;
            }

        }
        return ans;
    }
};
