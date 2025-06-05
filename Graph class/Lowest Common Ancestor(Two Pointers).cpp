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

vector<int> parent(1e6, -1);
vector<int> depth(1e6, 0);
	
void dfs(int source, vector<vector<int>> &adj){
	for(auto it:adj[source]){
		if(it!=parent[source]){
			parent[it] = source;
			depth[it] = depth[source]+1;
			dfs(it, adj);
		}
	}
}

void Solve(){
	int n;
	cin>>n;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1 ; i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	
	
	dfs(0, adj); 
	int digit1, digit2;
	cin>>digit1>>digit2;
	digit1--, digit2--;
	
	//making depths equal
	while(depth[digit1] != depth[digit2]){
		if(depth[digit1] > depth[digit2]){
			digit1 = parent[digit1];
		}else{
			digit2 = parent[digit2];
		}
	} 
	//now on same depth level
	while(digit1 != digit2){
		digit1 = parent[digit1];
		digit2 = parent[digit2];
	}
	
	cout<<digit1+1<<endl;  
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