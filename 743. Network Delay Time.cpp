// Time Complexity:
// O((V + E) * log V)
//or O(E log V)
// where V = number of nodes and E = number of edges.
// Each edge relaxation may insert a node into the priority queue,
// and each push/pop operation takes O(log V).

// Space Complexity:
// O(V + E)
// O(E) for the adjacency list,
// O(V) for the distance array,
// O(V) for the priority queue (at any instant).

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        q.push({0,k});

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int distance = it.first;
            int node = it.second;

            if (distance>dist[node])
                continue;

            for (auto neighbour : adj[node]) {
                if (distance + neighbour.second < dist[neighbour.first]) {
                    dist[neighbour.first] = distance + neighbour.second;
                    q.push({ dist[neighbour.first],neighbour.first});
                }
            }
        }

        int ans=0;
        for (int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX)   return -1;
            ans=max(ans,dist[i]);
        }
            

        return ans;
    }
};
