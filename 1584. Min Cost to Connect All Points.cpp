// Time Complexity:
// O(N² log N)
//
// For every node added to the MST, we compute distances
// to all other points and may push them into the priority queue.

// Space Complexity:
// O(N²) in the worst case
//
// The priority queue can contain O(N²) edges.

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {cost, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> visited(n, 0);

        pq.push({0, 0});

        int minCost = 0;

        while (!pq.empty()) {

            auto [cost, node] = pq.top();
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = 1;
            minCost += cost;

            // Try connecting every unvisited point
            for (int nextNode = 0; nextNode < n; nextNode++) {

                if (!visited[nextNode]) {

                    int distance =
                        abs(points[node][0] - points[nextNode][0]) +
                        abs(points[node][1] - points[nextNode][1]);

                    pq.push({distance, nextNode});
                }
            }
        }

        return minCost;
    }
};
