// Time Complexity:
// O(E * α(V) + V)
//
// O(E * α(V)) for performing Union operations on all edges.
// O(V) for counting the number of ultimate parents.
//
// Overall: O(E * α(V) + V)
// Since α(V) (Inverse Ackermann Function) is almost constant,
// it is commonly written as O(E + V).

// Space Complexity:
// O(V)
//
// O(V) for the parent array.
// O(V) for the size array.
//
// Overall: O(V)

class Solution {
  public:
    vector<int>size,parent;
    
    int findParent(int node){
        if(parent[node]==node)  return node;
        
        return parent[node]=findParent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        
        if(ulp_u==ulp_v)    return;
        
        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
    
    int countConnected(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        size.resize(V,1);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            unionbysize(u,v);
        }
        
        int cnt=0;
        for(int i=0;i<V;i++){
            if(parent[i]==i)    cnt++;
        }
        return cnt;
    }
};
