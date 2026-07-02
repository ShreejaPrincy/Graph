/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

class Solution {
public:
    void dfs(int row, int col, int baseRow, int baseCol,
             vector<vector<bool>>& visited,
             vector<vector<char>>& grid,
             vector<pair<int,int>>& shape) {
        
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = true;
        shape.push_back({row - baseRow, col - baseCol});

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               grid[newRow][newCol] == 'L' &&
               !visited[newRow][newCol]) {
                
                dfs(newRow, newCol, baseRow, baseCol, visited, grid, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'L' && !visited[i][j]) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, i, j, visited, grid, shape);
                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};
