/*
Time Complexity: O(V + E)

Every node and edge is checked once.

Space Complexity: O(V)

Color array + queue.
*/
class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbour : graph[node]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = !color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                if(bfs(i, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
