/*
Time Complexity: O(n * m)

Space Complexity: O(n * m)
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int prevColor = image[sr][sc];

        if(prevColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        vector<int> delRow = {0, 1, 0, -1};
        vector<int> delCol = {1, 0, -1, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                   image[newRow][newCol] == prevColor) {
                    
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }

        return image;
    }
};
