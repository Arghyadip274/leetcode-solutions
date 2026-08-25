class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> hash;
        int n=s.size();
        for (int i=0;i<=n-10;i++){
            string newS=s.substr(i,10);
            hash[newS]++;
            if(hash[newS]==2) ans.push_back(newS);
        }
        return ans;
    }
};
