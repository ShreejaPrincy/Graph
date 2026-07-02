/*
Time Complexity: O(m * n)

Every cell is visited at most once.

Space Complexity: O(m * n)

visited matrix + recursion stack.
*/

class Solution {
public:
    int m,n;
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>&visited){
        visited[i][j]=1;
    
        vector<int>drow={0,0,1,-1};
        vector<int>dcol={1,-1,0,0};

        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];

            if(nrow >= 0 && nrow < m&& ncol >= 0 && ncol < n && !visited[nrow][ncol]&& board[nrow][ncol]=='O')
                dfs(nrow,ncol,board,visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,0));

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&& !visited[i][0]){
                dfs(i,0,board,visited);
            }
            if(board[i][n-1]=='O'&&!visited[i][n-1]){
                dfs(i,n-1,board,visited);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'&& !visited[0][j]){
                dfs(0,j,board,visited);
            }
            if(board[m-1][j]=='O'&&!visited[m-1][j]){
                dfs(m-1,j,board,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
