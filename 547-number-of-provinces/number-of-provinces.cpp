class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>> &adjLs,unordered_map<int,bool> & visited ){
        visited[node] = 1;

        for(auto i: adjLs[node]){
            if(!visited[i]){
                dfs(i , adjLs, visited);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjacency List
        unordered_map<int, list<int>> adjLs;

        int n = isConnected.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        unordered_map<int,bool> visited;
        int provinces = 0;

        for(int i = 0;i < n;i++){
            if(!visited[i]){
                dfs( i , adjLs,visited);
                provinces ++;
            }
        }
        return provinces;
    }
};