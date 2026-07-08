class Solution {
public:
    string path="";
    vector<string> ans;
    void f(int open, int close){
        if(open==0 and close==0){
            ans.push_back(path);
            return;
        }
        if(open>0){
            path.push_back('(');
            f(open-1, close);
            path.pop_back();
        }
        if(close>open){
            path.push_back(')');
            f(open,close-1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        f(n,n);
        return ans;
    }
};
