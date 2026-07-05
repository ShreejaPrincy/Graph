/*
Small note

This line:

if(distance > dist[node])
    continue;

is mostly useful in priority queue version because old entries remain there.

In your set version, since you erase old distances, this line is not strictly necessary, but keeping it is safe. No issue.

Using set allows us to erase the previous larger distance of a node,
while priority queue keeps old entries and skips them later.
  */


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>dist(V,INT_MAX);
        
        set<pair<int,int>>st;
        
        st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int distance=it.first;
            int node=it.second;
            st.erase(it);
            
            if(distance > dist[node])
                continue;
            
            for(auto neighbour:adj[node]){
                int neighbourNode=neighbour.first;
                int weight=neighbour.second;
                
                if(distance+weight<dist[neighbourNode]){
                    
                    if(dist[neighbourNode]!=INT_MAX){
                        st.erase({dist[neighbourNode],neighbourNode});
                    }
                    
                    dist[neighbourNode]=distance+weight;
                    st.insert({dist[neighbourNode],neighbourNode});
                }
            }
        }
        return dist;
    }
};
/*
Time Complexity: O(E log V)

Each edge relaxation may cause erase and insert in set.
Set operations take O(log V).

Space Complexity: O(V + E)

Adjacency list takes O(V + E).
Distance array takes O(V).
Set takes O(V) approximately.
*/
