/*
Time Complexity: O(V + E)

Topological sort takes O(V + E).
Relaxing all edges takes O(V + E).

Space Complexity: O(V + E)

Adjacency list + visited array + stack + distance array.
*/

/*
Topo order guarantees parent comes before child.
So source will come before all reachable nodes.
Unreachable nodes may come anywhere, but dist = INF so skip them.
  */
class Solution {
  public:
    void dfs(int node, vector<bool>& vis,
             vector<vector<pair<int,int>>>& adj,
             stack<int>& st) {
        
        vis[node] = true;
        
        for(auto neighbour : adj[node]) {
            int adjNode = neighbour.first;
            
            if(!vis[adjNode]) {
                dfs(adjNode, vis, adj, st);
            }
        }
        
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(dist[node] != INT_MAX) {
                for(auto neighbour : adj[node]) {
                    int adjNode = neighbour.first;
                    int weight = neighbour.second;
                    
                    if(dist[node] + weight < dist[adjNode]) {
                        dist[adjNode] = dist[node] + weight;
                    }
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
