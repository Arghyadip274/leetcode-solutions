class Solution {
public:
    vector<int> vis;
    vector<int> pathVis;
    bool dfs(int node , vector<int>&vis, vector<int> &pathVis,vector<vector<int>>& g){
        vis[node]=1;
        pathVis[node]=1;
        for (auto v: g[node]){
            if(!vis[v]){
                if(dfs(v,vis,pathVis,g)) return 1;
            }
            else if (pathVis[v]) return 1;
        }
        pathVis[node]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vis.assign(n, 0);
        pathVis.assign(n, 0);
        vector<vector<int>> g(n);
        for (auto v: prereq){
            g[v[1]].push_back(v[0]);
        }
        for (int i=0;i<n;i++){
            if (!vis[i]){
                if (dfs(i,vis,pathVis, g)) return 0;
            }
        }
        return 1;
    }
};
