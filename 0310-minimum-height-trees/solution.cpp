class Solution {
public:
    vector<int> bfs(vector<int> &degree, vector<vector<int>> &g){
        queue<int> q;
        for(int i=0;i<g.size();i++){
            if (degree[i]==1) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int sz=q.size();
            for (int i=0;i<sz;i++){
                int node= q.front();
                q.pop();
                ans.push_back(node);
                for (auto v: g[node]){
                    degree[v]--;
                    if (degree[v]==1) q.push(v);
                }
            }
        }
        return ans;
    }


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> degree(n,0);
        for (auto v: edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
            degree[v[0]]++;
            degree[v[1]]++;
        }
        return bfs(degree,g);
    }
};
