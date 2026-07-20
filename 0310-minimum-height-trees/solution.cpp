class Solution {
public:

    vector<int> bfs(int n,vector<vector<int>> &g, vector<int> &degree){
        queue<int> q;
        for (int i=0;i<n;i++){
            if(degree[i]==1)q.push(i);
        }
        int rem=n;
        while (rem>2){
            int sz=q.size();
            rem=rem-sz;
            while (sz--){
                int node=q.front();
                q.pop();
                for (auto v:g[node]){
                    degree[v]--;
                    if(degree[v]==1) q.push(v);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()){
            int node =q.front();
            q.pop();
            ans.push_back(node);
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        vector<vector<int>> g(n);
        vector<int> degree(n,0);
        for (auto i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        return bfs(n,g,degree);



    }
};
