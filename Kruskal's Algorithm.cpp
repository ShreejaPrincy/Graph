// Time Complexity:
// O(E log E) + O(E * α(V))
//
// Sorting edges: O(E log E)
// DSU operations: O(E * α(V))
//
// Overall: O(E log E)

// Space Complexity:
// O(V + E)
//
// O(V) for parent and size arrays.
// O(E) for storing the sorted edges.

class Solution {
  public:
    vector<int>size,parent;
    int findParent(int node){
        if(node==parent[node])  return node;
        
        return parent[node]=findParent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        
        if(ulp_u==ulp_v)    return;
        
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        size.resize(V,1);
        parent.resize(V);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        vector<vector<int>>edge;
        
        for(auto ele:edges){
            edge.push_back({ele[2],ele[0],ele[1]});
        }
        
        sort(edge.begin(),edge.end());
        
        int sum=0;
        
        for(int i=0;i<edge.size();i++){
            int u=edge[i][1];
            int v=edge[i][2];
            int wt=edge[i][0];
            
            if(findParent(u)!=findParent(v)){
                unionbysize(u,v);
                sum+=wt;
            }
    
        }
        return sum;
    }
};
