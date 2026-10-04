class Solution {
public:
    vector<int> dist;
    void dijkstra(int src, vector<vector<pair<int,int>>> &g){
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        dist[src]=0;
        pq.push({src,0});
        while (!pq.empty()){
            auto[node, d]=pq.top();
            pq.pop();
            // if (d > dist[node]) continue;
            for (auto [u,v]:g[node]){
                int wt=d+v;
                if (wt<dist[u]) {
                    pq.push({u,wt});
                    dist[u]=wt;
                }
            }
        }
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        dist.assign(n+1,1e9);
        for(auto v:times){
            int src=v[0];
            int tar=v[1];
            int wt=v[2];
            g[src].push_back({tar,wt});
        }
        dijkstra(k,g);
        int minTime=0;
        for (int i=1;i<=n;i++){
            minTime=max(minTime,dist[i]);
        }
        if (minTime==1e9) return -1;
        else return minTime;
    }
};
