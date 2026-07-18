class Solution {
public:
    vector<int> ans;
    void bfs(int node, vector<vector<int>> &g,vector<int> &ind){
        priority_queue<int> pq;
        int n=g.size();
        for (int i=0;i<n;i++){
            if(ind[i]==0)pq.push(-i);
        }
        while (!pq.empty()){
            int cur=-pq.top();
            pq.pop();
            ans.push_back(cur);
            for (auto v:g[cur]){
                ind[v]--;
                if(ind[v]==0)pq.push(-v);
            }

        }
    }


    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> ind(n,0);
        for (auto i: prerequisites){
            g[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        bfs(0,g,ind);
        if(ans.size() != n)return {};
        return ans;

    }
};
