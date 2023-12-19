class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>hash;
        for(auto i:s){
            hash[i]++;
        }
        unordered_map<char,int>hashc;
        for(auto j:t){
            hashc[j]++;
        }
        if (hash == hashc){
            return true;
        }
        return false;
    }
};
