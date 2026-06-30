/*Agar hum kisi node par dobara pahunch rahe hain,
but woh node current node ka parent nahi hai,
toh cycle exists.
*/

/*
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

class Solution {
  public:
    bool bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<pair<int,int>> q;
        q.push({node, -1});
        visited[node] = 1;
        
        while(!q.empty()) {
            int nod = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int neighbour : adj[nod]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push({neighbour, nod});
                }
                else if(parent != neighbour) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfs(i, visited, adj)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
