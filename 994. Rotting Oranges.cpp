/*
Time Complexity: O(n * m)

Each cell is visited at most once.

Space Complexity: O(n * m)

Queue + visited matrix.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cntFresh = 0;
        int cntRottenFresh = 0;
        int time = 0;

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        vector<int> delRow = {0, 1, 0, -1};
        vector<int> delCol = {1, 0, -1, 0};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                   visited[newRow][newCol] != 2 && grid[newRow][newCol] == 1) {
                    
                    visited[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, t + 1});
                    cntRottenFresh++;
                }
            }
        }

        return cntFresh == cntRottenFresh ? time : -1;
    }
};
