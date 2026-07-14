// Time Complexity:
// O(N * M * α(N) + K log K)
//
// N = Number of accounts
// M = Average number of emails per account
// K = Total number of unique emails
//
// DSU operations: O(N * M * α(N))
// Sorting emails: O(K log K)

// Time Complexity:
// O(E * α(N) + E log E)
//
// E = Total number of emails

class Solution {
public:
    vector<int>parent,size;

    int findParent(int node){
        if(parent[node]==node)  return node;

        return parent[node]=findParent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u==ulp_v){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        size.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        //-----
        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];

                if(mp.find(s)==mp.end())    mp[s]=i;
                else{
                    int u=mp[s];
                    int v=i;

                    unionbysize(u,v);
                }
            }
        }
        vector<vector<string>>mergeMail(n);

        for(auto &it:mp){
            string mail=it.first;
            int node=it.second;

            int parentNode=findParent(node);

            mergeMail[parentNode].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)  continue;

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(mergeMail[i].begin(),mergeMail[i].end());

            for(auto &it:mergeMail[i])
                temp.push_back(it);

            ans.push_back(temp);
        }
        return ans;
    }
};
