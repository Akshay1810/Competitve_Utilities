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
	int l,r;
	cin>>l>>r;
	vector<int> arr = {76 ,784 ,234 ,888 ,95 ,17 ,557 ,813};
	int n = r;
    int m = arr.size();
	int ans = 0;
	for (int i = 1; i < (1 << m); i++) {

		int lcm = 1;
		for (int j = 0; j < m; j++) {
			// if jth bit of ith element is set then include it
			if ((i >> j) & 1) {
				// cout << primes[j] << " ";
				lcm = (lcm*arr[j])/__gcd(lcm, arr[j]);
			}
		}
		// cout << '\n';

		if (__builtin_popcount(i) % 2 == 0) {
			ans -= (n / lcm);
		}
		else {
			ans += (n / lcm);
		}
	}
    
    n = l;
    int ans1 = 0;
	for (int i = 1; i < (1 << m); i++) {

		int lcm = 1;
		for (int j = 0; j < m; j++) {
			// if jth bit of ith element is set then include it
			if ((i >> j) & 1) {
				// cout << primes[j] << " ";
				lcm = (lcm*arr[j])/__gcd(lcm, arr[j]);
			}
		}
		// cout << '\n';

		if (__builtin_popcount(i) % 2 == 0) {
			ans1 -= (n / lcm);
		}
		else {
			ans1 += (n / lcm);
		}
	}

	cout<<ans-ans1<<endl;    
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