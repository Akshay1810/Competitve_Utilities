// Problem: Holiday Accommodation
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/HOLI/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

vector<vector<pii>> vp(1e5+4); 
vector<int> height(1e5+4);
int tota = 0;
int dfs(int vertex, int parent, int edge, int n){
	int totchl = 0;
	for(auto child:vp[vertex]){
		// cout<<child<<endl;
		if(child.first == parent) continue;
		totchl += dfs(child.first, vertex, child.second, n);
	}
	// cout<<totchl<<" "<<vertex<<"**"<<endl;
	height[vertex] = totchl+1;
	tota += 2*min(height[vertex], n-height[vertex])*edge;
	return height[vertex];
}



int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int x = 1; x <= t; x++) 
    {
	    int n;
		cin>>n;
		tota = 0;
		for(int i = 0 ; i < n+1 ; i++){
			vp[i].clear();
		}
		//filling the adajcency list
		for(int i = 0 ; i < n-1 ; i++){
			int s,d,w;
			cin>>s>>d>>w;
			vp[s].pb({d,w});
			vp[d].pb({s,w});
		}
		// for(int i = 0 ; i <= n; i++){
			// for(int j = 0; j < vp[i].size(); j++){
				// cout<<"{"<<vp[i][j].ff<<" "<<vp[i][j].ss<<"}"<<" ";
			// }
			// cout<<endl;
		// }
		int val = dfs(1, -1, 0, n);
		// for(int i = 1 ; i <= n; i++){
			// cout<<height[i]<<" ";
		// }  
		cout<<"Case #"<<x<<": "<<tota<<endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}