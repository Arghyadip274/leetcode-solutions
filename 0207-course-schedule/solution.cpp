class Solution {
public:
    vector<int> vis;
    vector<int> pathVis;

    bool dfs(int node, vector<vector<int>> &g){
        vis[node]=1;
        pathVis[node]=1;
        for (auto v:g[node]){
            if(!vis[v]){
                if(dfs(v,g)) return 1;
            }
            else if(pathVis[v]) return 1;
        }
        pathVis[node]=0;
        return 0;
    }



    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vis.assign(n,0);
        pathVis.assign(n,0);
        vector<vector<int>> g(n);
        for (auto i:prerequisites){
            g[i[1]].push_back(i[0]);
        }
        for (int i=0;i<n;i++){
            if (!vis[i]){
                if(dfs(i,g)) return 0;
            }
        }
        return 1;
    }
};
