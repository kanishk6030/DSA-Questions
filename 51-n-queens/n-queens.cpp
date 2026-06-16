class Solution {
public:

    void addSolution(vector<string> &board,vector<vector<string>> &ans,int n){
                ans.push_back(board);
    }

    bool isSafe(int row,int col, vector<string> &board,int n){
        int x = row;
        int y = col;
        // Same row me nah ho
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }
        // same col me nah ho

        // daigonally nah ho
        x = row;
        y = col;

        while(x >=0 && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
                y--;
                x--;
        }
        //reset x and y
        x = row;
        y = col;
        while(x <n && y>=0){
            if(board[x][y] == 'Q'){
                return false;
            }
                y--;
                x++;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n){
        if(col == n){
            addSolution(board,ans,n);
            return;
        }

        // solve 1 case 
        for(int row = 0; row < n ; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,ans,board,n);
                //backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0,ans,board,n);

        return ans;
    }
};