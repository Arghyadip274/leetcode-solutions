class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hash;
        vector<string> ans;
        int n=s.size();
        for (int i=0;i<=n-10;i++){
            string curr=s.substr(i,10);
            hash[curr]++;
            if(hash[curr]==2) ans.push_back(curr);
            
        }
        return ans;
    }
};
