class Solution {
public:
    bool bfs(int src,vector<vector<int>> &g,vector<int>&colour){
        queue<int> q;
        q.push(src);
        colour[src]=0;
        while (!q.empty()){
            int node=q.front();
            q.pop();
            for (auto v:g[node]){
                if(colour[v]==-1){
                    colour[v]=1-colour[node];
                    q.push(v);
                }
                else if(colour[v]==colour[node]) return 0;
            }
        }
        return 1;
    }


    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> colour(n,-1);
        for (int i=0;i<n;i++){
            if (colour[i]==-1){
                if(!bfs(i,g,colour)) return 0 ;
            }
        }
        return 1;
    }
};
