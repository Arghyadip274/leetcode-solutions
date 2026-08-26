class Solution {
public:
    int characterReplacement(string s, int k) {
        int head =-1;
        int tail=0;
        int mf=0;
        int ans=0;
        int n=s.size();
        unordered_map<char,int> hash;
        while (tail<n){
            while (head+1<n){
                head++;
                hash[s[head]]++;
                mf=max(mf,hash[s[head]]);
                if(head-tail+1-mf>k){
                    hash[s[head]]--;
                    head--;
                    break;
                }
                ans=max(ans,head-tail+1);
            }
            hash[s[tail]]--;
            tail++;
            if (head<tail)head=tail-1;
        }
        return ans;
    }
};
