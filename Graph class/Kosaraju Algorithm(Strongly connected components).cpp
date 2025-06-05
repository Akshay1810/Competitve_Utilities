#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define int long long
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// debugger commands
// #ifndef ONLINE_JUDGE
// #include "header/debugger.h"
// #endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void dfs(int source, vector<vector<int>> &adjrev, vector<bool> &visited2){
	visited2[source] = true;
	for(auto it:adjrev[source]){
		if(!visited2[it]){
			dfs(it, adjrev, visited2);
		}
	}
}

void dfsfororder(int source, vector<int> &order,vector<vector<int>> &adjori, vector<bool> &visited){
	visited[source] = true;
	for(auto it:adjori[source]){
		if(!visited[it]){
			dfsfororder(it, order,adjori, visited);
		}
	}
	order.push_back(source);
}

int kosaraju(int n,vector<vector<int>> &edges){
	//form reversed adjacency matrix
	vector<vector<int>> adjrev(n+1);
	vector<vector<int>> adjori(n+1);
	vector<int> in_deg(n + 1, 0);
	
	for(auto it:edges){
		int x = it[0], y = it[1];
		adjori[x].push_back(y);
		adjrev[y].push_back(x);
		in_deg[y]++;
	}
	vector<int> order;
	vector<bool> visited(n+1,false), visited2(n+1, false);
    for(int i = 1 ; i <= n; i++){
    	if(!visited[i]){
    		dfsfororder(i,order,adjori,visited);
    	}
    }
    reverse(order.begin(), order.end());
	// for(auto it:order){
		// cout<<it<<" ";
	// }
	//Now we have topological sorting from the original graph
	//Now we will run dfs on every sink on it and will count components.
	int cnt = 0;
	for(int i = 0 ; i < order.size(); i++){
		int val = order[i];
		if(!visited2[val]){
			cnt++;
			dfs(val, adjrev, visited2);
		}
	}
	return cnt;
}

void Solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges;
	for(int i = 0; i < m; i++){
		int x,y;
		cin>>x>>y;
		// x++, y++;
		edges.push_back({x,y});
	}  
	
	int cnt = kosaraju(n,edges);
	cout<<cnt<<endl;  
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    // cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}