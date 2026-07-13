// Time Complexity: O(E log V)
// Space Complexity: O(V + E)

class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n,0);
        ways[0]=1;

        q.push({0,0});

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            long long distance = it.first;
            long long node = it.second;

            if (distance>dist[node])
                continue;

            for (auto neighbour : adj[node]) {
                if (distance + neighbour.second < dist[neighbour.first]) {
                    dist[neighbour.first] = distance + neighbour.second;
                    q.push({ dist[neighbour.first],neighbour.first});

                    ways[neighbour.first]=ways[node];
                }
                else if(distance + neighbour.second == dist[neighbour.first])
                    ways[neighbour.first]=(ways[neighbour.first]+ways[node])%MOD;
            }
        } 

        return ways[n-1];
    }
};
