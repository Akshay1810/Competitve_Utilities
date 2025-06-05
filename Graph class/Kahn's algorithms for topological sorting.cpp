#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> in_deg(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_deg[B]++;
    }

    // Min-heap for vertices with zero in-degree
    //we can use queue this was a code for special case when we wanted the lexicographically sorted numbers
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 1; u <= N; u++) {
        if (in_deg[u] == 0) {
            pq.push(u);
        }
    }

    vector<int> answer;
    answer.reserve(N);

    // Kahn's algorithm with min-heap
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        answer.push_back(u);

        for (int v : adj[u]) {
            if (--in_deg[v] == 0) {
                pq.push(v);
            }
        }
    }

    // If we didn't process all vertices, there's a cycle
    if ((int)answer.size() < N) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            cout << answer[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}

