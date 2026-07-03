/*
Time Complexity: O(V + E)

Every vertex and edge is visited once.

Space Complexity: O(V + E)

Adjacency list + visited array + recursion stack + stack.
*/

class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st){
        visited[node]=1;
        
        for(int neighbour:adj[node]){
            if(!visited[neighbour])
                dfs(neighbour,adj,visited,st);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        stack<int>st;
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
