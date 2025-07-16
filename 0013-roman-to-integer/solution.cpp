class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash;
        hash['I']=1;
        hash['V']=5;
        hash['X']=10;
        hash['L']=50;
        hash['C']=100;
        hash['D']=500;
        hash['M']=1000;
        int total=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='I'){
                if (i<s.size()-1 and (s[i+1]=='V' or s[i+1]=='X')){
                    total+=hash[s[i+1]]-hash[s[i]];
                    i++;
                }
                else total+=hash[s[i]];
            }
            else if (s[i]=='X'){
                if (i<s.size()-1 and (s[i+1]=='L' or s[i+1]=='C')){
                    total+=hash[s[i+1]]-hash[s[i]];
                    i++;
                }
                else total+=hash[s[i]];
            }
            else if (s[i]=='C'){
                if (i<s.size()-1 and (s[i+1]=='D' or s[i+1]=='M')){
                    total+=hash[s[i+1]]-hash[s[i]];
                    i++;
                }
                else total+=hash[s[i]];
            }
            else total+=hash[s[i]];
        }
        return total;

    }
};
