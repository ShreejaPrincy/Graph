// Time Complexity:
// O(E log E)
// or equivalently O(E log V)
//
// Building the adjacency list takes O(E).
// Each edge can be inserted into the priority queue.
// Every push/pop operation takes O(log V).
//
// Commonly written as: O(E log V)

// Space Complexity:
// O(V + E)
//
// O(E) for the adjacency list.
// O(V) for the visited array.
// O(V) for the priority queue (approximately in practice).

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>visited(V,0);
        
        pq.push({0,0});
        
        int sum=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int wt=it.first;
            int node=it.second;
            
            if(visited[node])   continue;
            
            visited[node]=1;
            
            sum+=wt;
            
            for(auto neighbour:adj[node]){
                int newNode=neighbour.first;
                int weight=neighbour.second;
                
                if(!visited[newNode]){
                    pq.push({weight,newNode});
                }
            }
        }
        return sum;
    }
};
