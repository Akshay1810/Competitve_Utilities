#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<int>> adjori, adjrev;
vector<bool> vis1, vis2;
vector<int> order, comp;

// 1st DFS: compute finishing order
void dfs1(int u) {
    vis1[u] = true;
    for (int v : adjori[u])
        if (!vis1[v]) dfs1(v);
    order.push_back(u);
}

// 2nd DFS on reversed graph: assign component ids
void dfs2(int u, int cid) {
    vis2[u] = true;
    comp[u] = cid;
    for (int v : adjrev[u])
        if (!vis2[v]) dfs2(v, cid);
}

// Kosaraju: fills comp[1..n] with component IDs 1..nc and returns nc
int kosaraju(int n) {
    vis1.assign(n+1, false);
    vis2.assign(n+1, false);
    comp.assign(n+1, 0);
    order.clear();

    for (int i = 1; i <= n; i++)
        if (!vis1[i]) dfs1(i);

    reverse(order.begin(), order.end());
    int nc = 0;
    for (int u : order) 
        if (!vis2[u]) {
            ++nc;
            dfs2(u, nc);
        }
    return nc;
}

void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> cost(n+1);
    rep(i, n) cin >> cost[i+1];

    vector<vector<int>> edges(m, vector<int>(2));
    adjori.assign(n+1, {});
    adjrev.assign(n+1, {});
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u; 
        edges[i][1] = v;
        adjori[u].push_back(v);
        adjrev[v].push_back(u);
    }

    // 1. Find SCCs
    int nc = kosaraju(n);

    // 2. Compute GCD cost per component
    vector<int> comp_gcd(nc+1, 0);
    for (int u = 1; u <= n; u++) {
        int cid = comp[u];
        comp_gcd[cid] = __gcd(comp_gcd[cid], cost[u]);
    }

    // 3. Build condensation graph (DAG)
    vector<vector<int>> dag(nc+1);
    for (auto &e : edges) {
        int u = comp[e[0]], v = comp[e[1]];
        if (u != v) dag[u].push_back(v);
    }
    // // remove duplicate edges
    // for (int i = 1; i <= nc; i++) {
    //     auto &adj = dag[i];
    //     sort(adj.begin(), adj.end());
    //     adj.erase(unique(adj.begin(), adj.end()), adj.end());
    // }

    // 4. Multi‐source BFS over (component, gcd_value) states
    vector<unordered_set<int>> seen(nc+1);
    queue<pair<int,int>> q;
    int ans = LLONG_MAX;
    for (int i = 1; i <= nc; i++) {
        ans = min(ans, comp_gcd[i]);
        seen[i].insert(comp_gcd[i]);
        q.emplace(i, comp_gcd[i]);
    }

    while (!q.empty() && ans > 1) {
        auto [u, g] = q.front(); 
        q.pop();
        ans = min(ans, g);
        for (int v : dag[u]) {
            int g2 = __gcd(g, comp_gcd[v]);
            if (!seen[v].count(g2)) {
                seen[v].insert(g2);
                q.emplace(v, g2);
            }
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}