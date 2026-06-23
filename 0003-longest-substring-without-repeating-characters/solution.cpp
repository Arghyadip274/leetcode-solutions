class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head=-1;
        int tail=0;
        unordered_map<char,int> hash;
        int ans=0;
        int n=s.size();
        while (tail<n){
            while (head+1<n and hash[s[head+1]]==0){
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
