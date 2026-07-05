//memory line

//Binary Maze shortest path:
//Grid + 4 directions + each move cost 1
//=> BFS  or dijikstra algo with queue


/*
Time Complexity: O(n * m)

Each cell is visited at most once.

Space Complexity: O(n * m)

Distance matrix + queue.
*/
class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        int m = mat[0].size();

        int sr = src[0], sc = src[1];
        int dr = dest[0], dc = dest[1];

        if(mat[sr][sc] == 0 || mat[dr][dc] == 0) {
            return -1;
        }

        if(sr == dr && sc == dc) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        dist[sr][sc] = 0;
        q.push({sr, sc});

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if(newRow >= 0 && newRow < n &&
                   newCol >= 0 && newCol < m &&
                   mat[newRow][newCol] == 1 &&
                   dist[newRow][newCol] == -1) {

                    dist[newRow][newCol] = dist[row][col] + 1;

                    if(newRow == dr && newCol == dc) {
                        return dist[newRow][newCol];
                    }

                    q.push({newRow, newCol});
                }
            }
        }

        return -1;
    }
};
