/*
Time Complexity: O(V + E)

Every vertex and edge is visited once.

Space Complexity: O(V + E)

Adjacency list + visited array + pathVisited array + recursion stack.
*/

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, adj, visited, pathVisited)) {
                    return true;
                }
            }
            else if(pathVisited[neighbour]) {
                return true;
            }
        }
        
        pathVisited[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
