//my code
// Time Complexity:
// O(N² × α(N))
//
// About N × N comparisons.

// Time Complexity:
// O(N² × α(N))
//
// About N(N-1)/2 comparisons.

class Solution {
public:
    vector<int> parent, size;

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    void unionbysize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        size.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        //----

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j)
                    continue;
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                    unionbysize(i, j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                cnt++;
        }
        return n - cnt;
    }
};


//------------------------------------------------------------------------------------
//Approach-2
class Solution {
public:
    vector<int> parent, size;

    int findParent(int node) {

        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0;
        int maxCol = 0;

        for (auto &stone : stones) {

            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        parent.resize(maxRow + maxCol + 2);
        size.resize(maxRow + maxCol + 2, 1);

        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }

        unordered_map<int, int> stoneNodes;

        for (auto &stone : stones) {

            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            unionBySize(rowNode, colNode);

            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int components = 0;

        for (auto &it : stoneNodes) {

            if (findParent(it.first) == it.first)
                components++;
        }

        return stones.size() - components;
    }
};

/*
Time Complexity:
O(N * α(M))

N = Number of stones
M = Total DSU nodes (maxRow + maxCol)

Each stone performs one Union operation.
DSU operations take O(α(M)).

Overall: O(N * α(M))


Space Complexity:
O(M)

M = maxRow + maxCol + 2

Parent Array  : O(M)
Size Array    : O(M)
HashMap Nodes : O(M)

Overall: O(M)
*/
