#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int node,vector<int> &vis, vector<int> &pathVis,vector<vector<int>>&g){
        vis[node]=1;
        pathVis[node]=1;
        for (auto it: g[node]){
            if (!vis[it] && dfs(it,vis,pathVis,g)){
                return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for (int i =0;i<numCourses;i++){
            if (!vis[i]){
                if (dfs(i,vis,pathVis,g)) return false;
            }
        }
        return true;


    }
};
