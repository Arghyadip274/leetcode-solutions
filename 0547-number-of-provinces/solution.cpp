class Solution {
public:
    vector<int>vis;
    void dfs(int node,vector<vector<int>>& g){
        vis[node]=1;
        for (auto v:g[node]){
            if(!vis[v]){
                dfs(v,g);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> g(n);
        vis.assign(n,0);
        for (int i=0;i<n;i++){
            for (int j=0;j<n ;j++){
                if(i!=j and isConnected[i][j]==1){
                    g[i].push_back(j);
                }
            }
        }
        int comp=0;
        for (int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(i,g);
                comp++;
            }
        }
        return comp;
    }
};
