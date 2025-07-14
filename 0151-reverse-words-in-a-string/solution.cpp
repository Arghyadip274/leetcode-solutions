class Solution {
public:
    string reverseWords(string s) {
        int l,r;
        l=0;
        r=s.size()-1;
        string temp="";
        string ans="";
        while (l <= r && s[l] == ' ') l++;
        while (l <= r && s[r] == ' ') r--;
        while(l<=r){
            char ch= s[l];
            if (ch!=' '){
                temp+=ch;
            }
            else if (!temp.empty()){
                if (ans!=""){
                    ans= temp+' '+ans;
                }
                else {
                    ans=temp;
                }
                temp="";
            }
            l++;
        }
        if (temp!="") {
            if( ans !="") ans=temp+' '+ans;
            else ans= temp;
        }
        return ans;
    }
};
