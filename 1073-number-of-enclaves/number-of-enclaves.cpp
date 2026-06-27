class Solution {
public:
void dfs(int row, int col ,vector<vector<int>> &vis , vector<vector<int>>& grid){
        int delRow[]= {-1, 0, +1, 0 };
        int delCol[]= {0, 1, 0, -1 };
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        //check for top , bottom , left, right
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol ,vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // This traversal for checking the edge 'O'
        //traverse first row and last row
        for(int j = 0; j < m; j++){
            //first row
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j ,vis, grid);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1, j ,vis, grid);
            }
        }
        //traverse first col and last col
        for(int i = 0; i < n; i++){
            //first row
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0 ,vis, grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1 ,vis, grid);
            }
        }

        int count = 0;
        
        for(int i = 0; i< n;i ++ ){
            for(int j = 0; j< m ;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count ++;
                }
            }
        }
        return count;
    }
};