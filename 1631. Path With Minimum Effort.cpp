/*
Time Complexity: O(n * m * log(n * m))

Space Complexity: O(n * m)

memory line////
Normal Dijkstra: newDist = dist + weight
This question: newEffort = max(currentEffort, heightDifference)
newEffort = max(current path effort, current edge difference)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> eff(n, vector<int>(m, INT_MAX));

        eff[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) {
                return effort;
            }

            if (effort > eff[r][c]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int diff = abs(heights[r][c] - heights[nrow][ncol]);
                    int neweff = max(effort, diff);

                    if (neweff < eff[nrow][ncol]) {
                        eff[nrow][ncol] = neweff;
                        pq.push({neweff, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};
