#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using pii = pair<int,int>;

/**
 * Computes single-source shortest paths on a weighted graph.
 *
 * @param s   The index of the source node.
 * @param AL  The adjacency list of the graph, where
 *            AL[u] is a vector of (v, w) pairs meaning
 *            an edge u -> v with weight w.
 * @return    A vector dist where dist[u] is the shortest
 *            distance from s to u (INF if unreachable).
 */
vector<int> dijkstra(int s, const vector<vector<pii>>& AL) {
    int V = AL.size();
    vector<int> dist(V, INF);
    dist[s] = 0;

    // Priority queue implemented as a set of (distance, node)
    set<pii> pq;
    for (int u = 0; u < V; ++u) {
        pq.emplace(dist[u], u);
    }

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        // If this distance is outdated, skip
        if (d > dist[u]) continue;

        // Relax all edges from u
        for (auto& [v, w] : AL[u]) {
            int nd = d + w;
            if (nd < dist[v]) {
                // Remove old entry and insert improved one
                pq.erase({dist[v], v});
                dist[v] = nd;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

// Example usage in main():
int main() {
    int V, E, s;
    cin >> V >> E >> s;
    vector<vector<pii>> AL(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        // For undirected graphs, also add:
        // AL[v].emplace_back(u, w);
    }

    vector<int> dist = dijkstra(s, AL);
    for (int u = 0; u < V; ++u) {
        if (dist[u] == INF) {
            cout << "SSSP(" << s << ", " << u << ") = INF\n";
        } else {
            cout << "SSSP(" << s << ", " << u << ") = " << dist[u] << "\n";
        }
    }

    return 0;
}
