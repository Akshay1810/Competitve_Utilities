struct DSU
{
    // union by rank
    // amortized complexity : O(alpha(n)) reverse ackerrman
    int n;
    vector<int> p, rankSize;
    DSU(int n) : n(n), p(n + 1), rankSize(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }
    int findp(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = findp(p[x]); // path compression
    }
    void unite(int a, int b)
    {
        a = findp(a);
        b = findp(b);
        if (a == b)
            return;
        if (rankSize[a] < rankSize[b])
            swap(a, b); // union by rank
        p[b] = a;
        rankSize[a] += rankSize[b];
    }
};