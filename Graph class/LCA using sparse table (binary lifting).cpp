#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
const int M = 20;           // enough for up to ~10^6 depth

vector<int> gr[N];
int dep[N], Par[N][M];

// preprocess depths and 2^j-ancestors
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    Par[u][0] = p;
    for(int j = 1; j < M; j++) {
        Par[u][j] = Par[ Par[u][j-1] ][ j-1 ];
    }
    for(int v : gr[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
}

// lift u up by diff levels
int lift(int u, int diff) {
    for(int j = 0; j < M; j++) {
        if(diff & (1 << j)) {
            u = Par[u][j];
        }
    }
    return u;
}

int LCAfunc(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    // bring u up to v's level
    u = lift(u, dep[u] - dep[v]);
    if(u == v) return u;
    // binary‐lift both until parents differ
    for(int j = M-1; j >= 0; j--) {
        if(Par[u][j] != Par[v][j]) {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    // now they differ but have same parent
    return Par[u][0];
}

vector<int> LCA(int n,vector<vector<int>>  edges, vector<vector<int>> queries)
{
    // 1) Clear previous state
    for(int i = 1; i <= n; i++) {
        gr[i].clear();
        dep[i] = 0;
        for(int j = 0; j < M; j++)
            Par[i][j] = 0;
    }

    // 2) Build the tree
    for(auto &e : edges) {
        int x = e[0], y = e[1];
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // 3) Root at 1 (or any node you choose)
    dfs(1, 0);

    // 4) Answer queries
    vector<int> ans;
    ans.reserve(queries.size());
    for(auto &q : queries) {
        ans.push_back(LCAfunc(q[0], q[1]));
    }
    return ans;
}
