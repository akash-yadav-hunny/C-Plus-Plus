class Solution {
public:
    bool dfs(int node , int des , vector<int>& vis , vector<vector<int>>& adj){
        vis[node]=1;
        if(node==des) return true;
        for(auto it:adj[node]){
            if(!vis[it] && dfs(it , des , vis , adj)) return true ;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        
        vector<vector<int>>adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n , 0);
        if(!vis[source] && dfs(source , des, vis , adj)) return true ;
        return false;
    }
};
