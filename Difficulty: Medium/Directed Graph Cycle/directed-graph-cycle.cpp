#include <bits/stdc++.h>
class Solution {
  public:
    bool checkCyclic(int node, unordered_map<int,bool>&visited,unordered_map<int ,list<int>> &adj, unordered_map<int,bool>&dfs_visited){
        visited[node] = true;
        dfs_visited[node] = true;
        
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleFound = checkCyclic(neighbour , visited, adj , dfs_visited);
                if(cycleFound){
                    return true;
                }
            }
            else if(dfs_visited[neighbour]){
                return true;
            }
        }
        
        dfs_visited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //Create adj list
        unordered_map<int ,list<int>> adj;
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        //call dfs for all components
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfs_visited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool cycleFound = checkCyclic(i , visited, adj , dfs_visited);
                if(cycleFound){
                    return true;
                }
            }
        }
        return false;
    }
};