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
        adj[B].push_back(A);
        in_deg[A]++;
    }
    queue<int> q;
    vector<int> val(N+1, 0);
    val[N] = 1;
    for (int u = 1; u <= N; u++) {
        if (in_deg[u] == 0) {
            q.push(u);
        }
    }
	
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
        	val[v] = (val[v] + val[u])%1000000007;
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }
	cout<<val[1]<<endl;
    return 0;
}
