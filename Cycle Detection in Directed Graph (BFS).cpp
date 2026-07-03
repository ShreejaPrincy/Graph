/*
Time Complexity: O(V + E)

Every vertex and edge is processed once.

Space Complexity: O(V + E)

Adjacency list + indegree array + queue.
*/


class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(int neighbour : adj[node]) {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return count != V;
    }
};
