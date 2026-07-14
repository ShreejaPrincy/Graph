// Time Complexity:
// O(Q * α(N))
//
// Q = Number of queries
// N = Number of elements
//
// Each Find and Union operation takes O(α(N))
// due to Path Compression.

// Space Complexity:
// O(N)
//
// O(N) for the parent array.

class Solution {
  public:
    vector<int>parent,size;
    int findParent(int node){
        if(node==parent[node])
            return node;
        
        return parent[node]=findParent(parent[node]);
    }
    void Union(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        
        if(ulp_u==ulp_v)    return;
        
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
        
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                Union(queries[i][1],queries[i][2]);
            }
            else{
                ans.push_back(findParent(queries[i][1]));
            }
        }
        return ans;
    }
};
