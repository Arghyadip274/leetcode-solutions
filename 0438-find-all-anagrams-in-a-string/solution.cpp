class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;
        unordered_map<char,int> hashP;
        unordered_map<char,int> hashS;

        for (int i=0;i<p.size();i++){
            hashP[p[i]]++;
            hashS[s[i]]++;
        }
        if(hashP==hashS) ans.push_back(0);

        for (int i=p.size();i<s.size();i++){
            hashS[s[i]]++;
            int left=i-p.size();
            hashS[s[left]]--;
            if(hashS[s[left]]==0) hashS.erase(s[left]);
            if(hashP==hashS) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
