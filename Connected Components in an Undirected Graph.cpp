/*
Time Complexity: O(V + E)

Space Complexity: O(V + E)
*/

class Solution {
	public:
	void dfs(vector<vector<int>> &adj, int node, vector<int>& comp, vector<int>& visited) {
		
		visited[node] = 1;
		comp.push_back(node);
		
		for(int i = 0; i < adj[node].size(); i++) {
			int neighbour = adj[node][i];
			
			if(!visited[neighbour]) {
				dfs(adj, neighbour, comp, visited);
			}
		}
	}
	
	vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {

		vector<vector<int>> adj(V);
		
		for(int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<int> visited(V, 0);
		vector<vector<int>> ans;
		
		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				vector<int> components;
				dfs(adj, i, components, visited);
				ans.push_back(components);
			}
		}
		
		return ans;
	}
};
