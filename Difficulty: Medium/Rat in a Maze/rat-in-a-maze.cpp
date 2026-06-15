class Solution {
  public:
  
  bool isSafe(int newx,int newy,vector<vector<bool>>& visited, vector<vector<int>>&maze,int n){
      if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && maze[newx][newy] == 1){
          return true;
      }
      else{
          return false;
      }
  }
  
  void solve(int x, int y,vector<vector<int>>& maze, int n,vector<string> &ans,vector<vector<bool>> &visited, string path ){
      //base  case
      if(x == n-1 && y==n-1){
          ans.push_back(path);
          return;
      }
      
      //4 Movement 
      //D, L, R, U
      
      //Down
      if(isSafe(x+1,y,visited,maze,n)){
          visited[x][y] = 1;
          solve(x+1,y,maze,n,ans,visited,path + 'D');
          visited[x][y] = 0;
      }
      //left
      if(isSafe(x,y-1,visited,maze,n)){
          visited[x][y] = 1;
          solve(x,y-1,maze,n,ans,visited,path + 'L');
          visited[x][y] = 0;
      }
      //right
      if(isSafe(x,y+1,visited,maze,n)){
          visited[x][y] = 1;
          solve(x,y+1,maze,n,ans,visited,path + 'R');
          visited[x][y] = 0;
      }
      //up
      if(isSafe(x-1,y,visited,maze,n)){
          visited[x][y] = 1;
          solve(x-1,y,maze,n,ans,visited,path + 'U');
          visited[x][y] = 0;
      }
      
  }
vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path = "";
        if(maze[0][0] == 0) return ans;
        
        solve(0,0,maze,n,ans,visited,path);
        return ans;
}
};