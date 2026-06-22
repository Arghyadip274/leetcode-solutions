class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int n= strs.size();
        sort(strs.begin(), strs.end());
        for (int i=0;i<min(strs[0].size(), strs[n-1].size());i++){
            if (strs[0][i]==strs[n-1][i]) prefix.push_back(strs[0][i]);
            else return prefix;
        }
        return prefix;
    }
};
