//Q. shortest path in weighted undirected graph

//TC: O(E log V)
//SC: O(V + E)
class Solution {
	public:
	vector<int> shortestPath(int n, int m, vector<vector<int>> & edges) {
		
		vector<vector<pair<int, int>> >adj(n + 1);
		
		for (int i = 0; i<m; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		
		pq.push({0, 1});
		
		vector<int>dist(n + 1, INT_MAX);
		dist[1] = 0;
		
		vector<int>parentNode(n + 1);
		for (int i = 0; i<n + 1; i++) {
			parentNode[i] = i;
		}
		
		while (!pq.empty()) {
			
			int node = pq.top().second;
			int distance = pq.top().first;
			pq.pop();
			
			if (distance>dist[node])
				continue;
			
			for (auto Nnode:adj[node]) {
				
				int NeighbourNode = Nnode.first;
				int weight = Nnode.second;
				
				if (distance + weight<dist[NeighbourNode]) {
					
					dist[NeighbourNode] = distance + weight;
					pq.push({dist[NeighbourNode], NeighbourNode});
					
					parentNode[NeighbourNode] = node;
				}
			}
			
		}
		if(dist[n]==INT_MAX)    return {-1};
		
		vector<int>ans;
		
		int destnode = n;
		
		while (parentNode[destnode] != destnode) {
			ans.push_back(destnode);
			destnode = parentNode[destnode];
		}
		ans.push_back(1);
		ans.push_back(dist[n]);
		
		reverse(ans.begin(), ans.end());
		
		return ans;
	}
};
