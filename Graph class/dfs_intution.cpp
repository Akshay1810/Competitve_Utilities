void dfs(int vertex, vector<bool> &visited, vector<vector<int>> &adj)
{
    // Take action on vertex after entering the vertex
    visited[vertex] = true;
    for (int child : adj[vertex])
    {
        if (visited[child])
            continue;
        // take action on child before entering the child node
        dfs(child, visited, adj);
        // take action on child after entering the child node
    }
    // take action on vertex before entering the vertex
}