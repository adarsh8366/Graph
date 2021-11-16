class Solution {
public:
    void dfs(int child,int par,vector<bool>&vis,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&intime,vector<int>&lowtime,int &time) {
        vis[child] = true;
        intime[child] = time;
        lowtime[child] = time++;
        
        for(auto &it:adj[child]) {
            if(it==par) {
                continue;
            }
            if(!vis[it]) {
                dfs(it,child,vis,adj,ans,intime,lowtime,time);
                lowtime[child] = min(lowtime[child],lowtime[it]);
                if(lowtime[it]>intime[child]) {
                    ans.push_back({child,it});
                }
            } else {
                lowtime[child] = min(lowtime[child],lowtime[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> intime(n),lowtime(n);
        vector<vector<int>> adj(n);
        for(auto &it:connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        vector<bool> vis(n,false);
        int time = 0;
        for(int i=0;i<n;++i) {
            if(!vis[i]) {
                dfs(i,-1,vis,adj,ans,intime,lowtime,time);
            }
        }
       return ans; 
    }
};
