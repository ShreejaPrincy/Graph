// Time Complexity:
// O(E * α(N) + N)
//
// E = number of connections
// N = number of computers
//
// Union operations: O(E * α(N))
// Counting components: O(N)
//
// Overall: O(E + N)

// Space Complexity:
// O(N)
//
// O(N) for parent array.
// O(N) for size array.

class Solution {
public:
    vector<int>parent,size;
    int extraEdges;

    int findParent(int node){
        if(parent[node]==node)  return node;

        return parent[node]=findParent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u==ulp_v){
            extraEdges++;
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        extraEdges=0;

        size.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            unionbysize(u,v);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                components++;
        }
        if(components-1<=extraEdges)   return components-1;
        return -1;
    }
};
