void solve()
{
    long long n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (long long i = 0; i < n - 1; i++)
    {
        long long x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // Use BFS to separate vertices into two sets
    vector<int> color(n, -1);
    set<long long> st1, st2;
    queue<int> q;

    // Start BFS from vertex 0
    q.push(0);
    color[0] = 0;
    st1.insert(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        // Process all neighbors
        for (int next : adj[curr])
        {
            if (color[next] == -1)
            {
                color[next] = 1 - color[curr]; // Assign opposite color
                if (color[next] == 0)
                    st1.insert(next);
                else
                    st2.insert(next);
                q.push(next);
            }
        }
    }
    for (auto it : st1)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : st2)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << 1ll * (st1.size() * st2.size()) - (n - 1) << endl;
}