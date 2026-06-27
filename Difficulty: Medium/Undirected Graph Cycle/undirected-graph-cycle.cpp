class Solution {
  public:
    bool isCycleBFS(int src,unordered_map<int,list<int>> &adj, unordered_map<int,bool> &vis){
        unordered_map<int,int> parent;
        parent[src] = -1;
        vis[src] = true;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neigh : adj[front]){
                if(vis[neigh] == true && neigh != parent[front]){
                    return true;
                }
                else if( !vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = 1;
                    parent[neigh] = front;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>> adj;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
        
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //for disconnected graph
        unordered_map<int,bool> vis;
        for(int i = 0 ; i < V;i++){
            if(!vis[i]){
                bool ans = isCycleBFS(i , adj , vis);
                if (ans == 1){
                    return true;
                }
            }
        }
        return false;
    }
};