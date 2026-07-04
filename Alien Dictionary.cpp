/*
Time Complexity: O(total characters + E)

Space Complexity: O(26 + E)
*/

class Solution {
public:
    vector<int> topoSort(int V, vector<bool>& present, vector<set<int>>& adj) {
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int node : adj[i]) {
                indegree[node]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int neighbour : adj[node]) {
                indegree[neighbour]--;

                if(present[neighbour] && indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return topo;
    }

    string findOrder(vector<string>& words) {
        int n = words.size();

        vector<bool> present(26, false);

        for(int i = 0; i < n; i++) {
            for(char ch : words[i]) {
                present[ch - 'a'] = true;
            }
        }

        vector<set<int>> adj(26);

        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int size = min(s1.size(), s2.size());
            bool foundDiff = false;

            for(int j = 0; j < size; j++) {
                if(s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].insert(v);
                    foundDiff = true;
                    break;
                }
            }

            if(!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = topoSort(26, present, adj);

        int countPresent = 0;

        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                countPresent++;
            }
        }

        if(topo.size() != countPresent) {
            return "";
        }

        string ans = "";

        for(int node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};
