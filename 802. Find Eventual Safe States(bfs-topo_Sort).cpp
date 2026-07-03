/*Eventual Safe States using Kahn:
Reverse graph + outdegree.
Start from nodes with outdegree 0.*/

/*
Time Complexity: O(V + E) + O(V log V)

BFS processes every node and edge once.
Sorting answer takes O(V log V).

Space Complexity: O(V + E)

Reverse graph + outdegree array + queue.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> revGraph(V);
        vector<int> outdegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int neighbour : graph[i]) {
                revGraph[neighbour].push_back(i);
                outdegree[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int parent : revGraph[node]) {
                outdegree[parent]--;

                if(outdegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
