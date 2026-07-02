/*
Time Complexity: O(n * m)

Every cell is pushed into queue at most once.

Space Complexity: O(n * m)

ans matrix + visited matrix + queue.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans[r][c] = t;

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !visited[nrow][ncol]) {
                    
                    visited[nrow][ncol] = true;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        return ans;
    }
};
