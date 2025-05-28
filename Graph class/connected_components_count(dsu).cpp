#include <bits/stdc++.h>
using namespace std;

// DSU Class
class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Function to count connected components using DSU
int countConnectedComponents(int n, vector<pair<int, int>> &edges)
{
    DSU dsu(n);
    for (auto &edge : edges)
    {
        dsu.unite(edge.first, edge.second);
    }

    // Count the number of unique components
    set<int> uniqueComponents;
    for (int i = 0; i < n; ++i)
    {
        uniqueComponents.insert(dsu.find(i));
    }

    return uniqueComponents.size();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; // Convert to 0-based indexing
        --v; // Convert to 0-based indexing
        edges.emplace_back(u, v);
    }

    cout << countConnectedComponents(n, edges) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases are needed
    while (t--)
    {
        solve();
    }

    return 0;
}
