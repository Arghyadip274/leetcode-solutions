class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void f(int start,int n, int k){
        if(k==0){
            ans.push_back(path);
            return;
        }

        for (int i=start;i<=n;i++){
            path.push_back(i);
            f(i+1,n,k-1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        f(1,n,k);
        return ans;
    }
};
