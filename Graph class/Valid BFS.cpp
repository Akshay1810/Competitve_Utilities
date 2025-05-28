// Problem: D. Valid BFS?
// Contest: Codeforces - Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1037/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define int long long
#define pyes cout << "Yes" << "\n";
#define pno cout << "No" << "\n";
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

void Solve(){
	int n;
	cin>>n;
    vector<unordered_set<int>> adj(3e5+1);
    for(int i = 0 ; i < n-1 ; i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].insert(y);
    	adj[y].insert(x);
    }
    vector<int> v;
    for(int i = 0 ; i < n; i++){
    	int x;
    	cin>>x;
    	v.push_back(x);
    }
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(1);
    visited[1] = true;
    int i = 1;
    if(v[0] != 1){
    	pno
    	return;
    }
    while(!q.empty()){
    	int val = q.front();
    	q.pop();
    	for(;i < n; i++){
    		int exnbr = v[i];
    		if(adj[val].find(exnbr) != adj[val].end()){
	    		q.push(exnbr);
	    		adj[val].erase(exnbr);
	    		visited[exnbr] = true;
	    		continue;
	    	}
	    	
	    	if(!adj[val].empty()){
	    		for(auto it:adj[val]){
	    			if(visited[it] == false){
	    				pno
	    				return;
	    			}
	    		}
	    		break;
	    	}else{
	    		break;
	    	}
    	}
    }
    pyes
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