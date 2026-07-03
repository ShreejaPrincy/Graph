/*
Time Complexity: O(V + E)

Every vertex and edge is processed once.

Space Complexity: O(V + E)

Adjacency list + indegree array + queue.
*/

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbour : adj[node]) {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};
