// Function to perform DFS on the graph
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

// Function to count the number of connected components
int countConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Build the adjacency list
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int components = 0;

    // Traverse all nodes
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            ++components;
            dfs(i, adj, visited);
        }
    }

    return components;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges.push_back({x, y});
    }
    cout << countConnectedComponents(n, edges) << endl;
}