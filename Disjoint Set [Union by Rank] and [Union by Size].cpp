//Time Complexity

// Find Parent:
// O(α(N))

// Union by Rank:
// O(α(N))

// Union by Size:
// O(α(N))


// Space Complexity:
// O(N)
//
// O(N) for parent array
// O(N) for rank array
// O(N) for size array
//
// Overall: O(N)

class DisjointSet {

    vector<int> parent, rank, size;

public:

    DisjointSet(int n) {

        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {

            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {

            parent[ulp_v] = ulp_u;
        }
        else {

            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
};
