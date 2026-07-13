// Time Complexity:
// O((k + 1) * E)
// where E = number of flights (edges).
// In the worst case, we may process all edges for each level
// up to k + 1 flights.

// Space Complexity:
// O(V + E)
// where V = number of cities (nodes)
// and E = number of flights (edges).
// O(E) for the adjacency list,
// O(V) for the distance array,
// and O(E) in the worst case for the queue.


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stop = it.first;
            int node = it.second.first;
            int distance = it.second.second;

            if (k < stop)
                continue;

            for (auto neighbour : adj[node]) {
                if (distance + neighbour.second < dist[neighbour.first] && stop<=k) {
                    dist[neighbour.first] = distance + neighbour.second;
                    q.push({stop + 1, {neighbour.first, dist[neighbour.first]}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
