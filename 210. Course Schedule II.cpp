/*
Time Complexity: O(V + E)

Space Complexity: O(V + E)
*/
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
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

        if(ans.size() == V) return ans;
        return {};
    }
};
