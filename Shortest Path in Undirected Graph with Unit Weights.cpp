/*
Time Complexity: O(V + E)

Every node and edge is processed.

Space Complexity: O(V + E)

Adjacency list + distance array + queue.


Unweighted shortest path = BFS
First time a node is reached, that is shortest distance
*/

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, INT_MAX);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbour : adj[node]) {
                if(dist[node] + 1 < dist[neighbour]) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        if(dist[dest] == INT_MAX) return -1;
        return dist[dest];
    }
};
