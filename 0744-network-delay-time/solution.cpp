class Solution {
public:
    void djisktra(int node , vector <int> &dis,vector<vector<pair<int,int>>>& g){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dis[node]=0;
        pq.push({node,0});
        while (!pq.empty()){
            auto [src,d]=pq.top();
            pq.pop();
            if (d>dis[src]) continue;
            for (auto [u,v]:g[src]){
                if(d+v < dis[u]){
                    dis[u]=d+v;
                    pq.push({u,dis[u]});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>g(n+1);
        for (auto i:times){
            g[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        djisktra(k,dis,g);
        int ans=0;
        for (int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
