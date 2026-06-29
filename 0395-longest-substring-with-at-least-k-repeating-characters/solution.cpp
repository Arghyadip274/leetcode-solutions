class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0|| k>n) return 0;
        if (k<=1) return n;
        
        unordered_map<char,int> hash;
        for(char c: s){
            hash[c]++;
        }

        int idx=0;
        while(idx<n and hash[s[idx]]>=k){
            idx++;
        }
        if (idx==n) return n;
        int left=longestSubstring(s.substr(0,idx),k);
        while (idx<n and hash[s[idx]]<k){
            idx++;
        }
        int right =longestSubstring(s.substr(idx),k);
        return max(left,right);
    }
};
