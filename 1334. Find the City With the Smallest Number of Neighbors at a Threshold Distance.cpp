// Time Complexity:
// O(V^3)
// Floyd-Warshall runs three nested loops over all vertices.
//
// Counting reachable cities takes O(V^2).
//
// Overall: O(V^3)

// Space Complexity:
// O(V^2)
// for the distance matrix.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Distance from a node to itself is 0
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Fill the adjacency matrix
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int minReachable = INT_MAX;
        int ans = -1;

        // Count reachable cities for every city
        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    count++;
            }

            // In case of tie, choose the greater city index
            if (count <= minReachable) {
                minReachable = count;
                ans = i;
            }
        }

        return ans;
    }
};
