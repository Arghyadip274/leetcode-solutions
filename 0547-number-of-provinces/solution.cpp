class Solution {
public:
    void dfs(int node, vector<vector<int>> &g,vector<bool> &vis){
        vis[node]=1;
        for (auto v:g[node]){
            if(!vis[v]) dfs(v,g,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>>g(n,vector<int>(n));
        vector<bool> vis(n,0);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int val=nums[i][j];
                if(val==1 and i!=j) {
                    g[i].push_back(j);
                }
            }
        }
        int comp=0;
        for (int i =0;i<n;i++){
            if (!vis[i]){
                dfs(i,g,vis);
                comp++;
            }
        }
        return comp;
    }
};
