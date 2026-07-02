/*
Time Complexity: O(V + E)

Every node and edge is checked once.

Space Complexity: O(V)

Color array + recursion stack.
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        for(int neighbour : graph[node]) {
            if(color[neighbour] == -1) {
                color[neighbour] = !color[node];

                if(dfs(neighbour, graph, color) == false) {
                    return false;
                }
            }
            else if(color[neighbour] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                color[i] = 0;

                if(dfs(i, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
