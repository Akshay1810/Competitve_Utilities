const int N = 1e5 + 10;
vector<int> g[N]; // graph edges
int depth[N], height[N];
// time complexity: O(m+n)
void dfs(int vertex, int parent)
{
    // Take action on vertex after entering the vertex
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;
        // take action on child before entering the child node
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
        // take action on child after entering the child node
    }
    // take action on vertex before entering the vertex
}