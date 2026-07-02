/*
Time Complexity: O(m * n)

Every cell is visited at most once.

Space Complexity: O(m * n)

Visited matrix + DFS recursion stack.

*/

class Solution {
public:
    int m, n;

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if(newRow >= 0 && newRow < m &&
               newCol >= 0 && newCol < n &&
               !visited[newRow][newCol] &&
               grid[newRow][newCol] == 1) {
                
                dfs(newRow, newCol, grid, visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1 && !visited[i][0]) {
                dfs(i, 0, grid, visited);
            }

            if(grid[i][n - 1] == 1 && !visited[i][n - 1]) {
                dfs(i, n - 1, grid, visited);
            }
        }

        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1 && !visited[0][j]) {
                dfs(0, j, grid, visited);
            }

            if(grid[m - 1][j] == 1 && !visited[m - 1][j]) {
                dfs(m - 1, j, grid, visited);
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
