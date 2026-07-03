/*
Safe node = does not lead to cycle.

DFS:
visited + pathVisited

If neighbour is in current path → cycle → unsafe.

If DFS finishes without cycle → check[node] = 1 → safe.
*/

/*
Time Complexity: O(V + E)

Every node and every edge is visited once.

Space Complexity: O(V)

visited array + pathVisited array + check array + recursion stack.
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited,
             vector<int>& pathVisited,
             vector<int>& check) {
        
        visited[node] = 1;
        pathVisited[node] = 1;

        for(int neighbour : graph[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour, graph, visited, pathVisited, check)) {
                    return true;
                }
            }
            else if(pathVisited[neighbour]) {
                return true;
            }
        }

        pathVisited[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> check(n, 0);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, pathVisited, check);
            }
        }

        vector<int> safeNodes;

        for(int i = 0; i < n; i++) {
            if(check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
