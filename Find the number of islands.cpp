/*
Time Complexity: O(n * m)

Every cell is visited at most once.
For each cell, we check 8 directions.

Space Complexity: O(n * m)

Visited matrix + recursion stack.
*/

class Solution {
  public:
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        visited[r][c] = true;

        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int newrow = r + delrow;
                int newcol = c + delcol;

                if(newrow >= 0 && newrow < n &&
                   newcol >= 0 && newcol < m &&
                   grid[newrow][newcol] == 'L' &&
                   !visited[newrow][newcol]) {
                    
                    dfs(newrow, newcol, visited, grid);
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'L' && !visited[i][j]) {
                    cnt++;
                    dfs(i, j, visited, grid);
                }
            }
        }

        return cnt;
    }
};
