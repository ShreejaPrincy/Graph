/*
Time Complexity: O(n^2)

For every node, we scan the full row of adjacency matrix.

Space Complexity: O(n)

Visited array + recursion stack.
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        int n = isConnected.size();

        for(int neighbour = 0; neighbour < n; neighbour++) {
            if(isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};
