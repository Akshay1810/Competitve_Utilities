// Problem: B. Ideal Point
// Contest: Codeforces - Educational Codeforces Round 143 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1795/problem/B
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

void Solve(){
	int n,k;
	cin>>n>>k;
	vector<int> pre(52, 0);
	for(int i = 0 ; i < n ; i++){
		int l,r;
		cin>>l>>r;
		if(l > k || r < k) continue;
		pre[l] += 1;
		pre[r+1] -= 1;
	}
	for(int i = 1 ; i < 52 ; i++){
		pre[i] = pre[i-1]+pre[i];
	}
	// cerr<<"[";
	// for(auto it:pre){
		// cerr<<it<<" ";
	// }     
	// cerr<<"]";
	int ans = max_element(all(pre)) - pre.begin();
	int cnt = 0;
	for(auto it:pre){
		if(it == pre[ans]){
			cnt++;
		}
	}
	if(ans == k and cnt == 1){
		pyes
	}else{
		pno
	}
	// cout<<endl;
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