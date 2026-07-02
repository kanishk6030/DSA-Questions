class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> key(V);
        vector<bool> mst(V);
        vector<int> parent(V);
        
        for(int i = 0 ; i < V; i ++){
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }
        // Algo
        key[0] = 0;
        parent[0] = -1;
        
        for(int i = 1; i < V ; i++){
            int mini = INT_MAX;
            int u;
            
            //find the min wali node
            for(int v = 0; v < V; v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }
            
            //mark min node as true
            mst[u] = true;
            
            //check its  addjacent nodes
            for(auto it: adj[u]){
                int v = it.first;
                int w = it.second;
                if(mst[v] == false && w < key[v]){
                    parent[v] = u;
                    key[v] = w;
                }
            }
            
        }
        int weight = 0;
        for(int i = 0; i < V; i++)
            weight += key[i];
        
        return weight;
        
    }
};