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

struct DSU {
	//union by rank
	//amortized complexity : O(alpha(n)) reverse ackerrman
    int n;
    vector<int> p, rankSize;
    DSU(int n) : n(n), p(n+1), rankSize(n+1, 1) {
        for(int i=1; i<=n; i++) p[i] = i;
    }
    int findp(int x) {
        if(p[x] == x) return x;
        return p[x] = findp(p[x]);//path compression
    }
    void unite(int a, int b) {
        a = findp(a); b = findp(b);
        if(a == b) return;
        if(rankSize[a] < rankSize[b]) swap(a,b); //union by rank
        p[b] = a;
        rankSize[a] += rankSize[b];
    }
};

void Solve(){
	int n,m;
	cin>>n>>m;
    DSU dsu(n);
    
    vector<vector<int>> edges;
    for(int i = 0; i < m ; i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	edges.push_back({x,y,w});
    }
    
    sort(all(edges), [](auto &A, auto &B){ return A[2] < B[2]; });
    int ans = 0;
    for(auto it:edges){
    	int x = it[0], y = it[1],z = it[2];
    	if(dsu.findp(x) != dsu.findp(y)){
    		dsu.unite(x,y);
    		ans += z;
    	}
    }
    cout<<ans<<endl;
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