/*
Time Complexity: O(E log V)

Each edge can cause a priority queue push.
Each push/pop takes log V time approximately.

Space Complexity: O(V + E)

Adjacency list takes O(V + E).
Distance array takes O(V).
Priority queue can store up to O(E) entries in worst case.
*/

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});   // remove if graph is directed
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(distance > dist[node])
                continue;

            for(auto neighbour : adj[node]) {

                int adjNode = neighbour.first;
                int weight = neighbour.second;

                if(distance + weight < dist[adjNode]) {

                    dist[adjNode] = distance + weight;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
