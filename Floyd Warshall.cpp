// Time Complexity:
// O(V^3)
// Three nested loops over all vertices.

// Space Complexity:
// O(1)
// No extra space is used (excluding the input matrix),
// as the distance matrix is updated in-place.

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
      
        for(int via=0;via<dist.size();via++){
            for(int i=0;i<dist.size();i++){
                for(int j=0;j<dist.size();j++){
                  
                    if(dist[i][via]!=1e8 && dist[via][j]!=1e8)
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }

        // Negative Cycle Detection
        // If any diagonal element becomes negative,
        // then the graph contains a negative weight cycle.
        //
        // for (int i = 0; i < V; i++) {
        //     if (dist[i][i] < 0) {
        //         // Negative Weight Cycle Exists
        //     }
        // }

    }
};
