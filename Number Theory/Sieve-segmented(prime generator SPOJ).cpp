// Problem: Prime Generator
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PRIME1/
// Memory Limit: 1536 MB
// Time Limit: 6000 ms
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

//segmented sieve code
const int siz = 1e5;
vector<bool> s(siz+1, 1);
vector<int> onlyprimes;
void sieve(){
	s[0] = s[1] = 0;
	for(int i =2; i*i < siz; i++){
		if(s[i]){
			for(int j = i*i; j < siz; j+=i){
				s[j] = 0;
			}
		}
	}
	
	for(int i = 0 ; i <= siz; i++){
		if(s[i] == 1){
			onlyprimes.pb(i);
		}
	}
}


int32_t main(){
	sieve();
	// for(auto it:onlyprimes){
		// cout<<it<<" ";
	// }
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		vector<int> segsieve(b-a+1, 1);
		for(int i = 0 ; i < onlyprimes.size() ;i++){
			if(onlyprimes[i]*onlyprimes[i] > b){
				break;
			}
			
			//finding nearest starting point
			int rem = a%onlyprimes[i];
			int start = a-rem;
			//satrt marking the numbers from here
			
			if(onlyprimes[i] >= a and onlyprimes[i] <= b){
				start = 2*onlyprimes[i];
			}
			for(int j = start ; j <= b; j+=onlyprimes[i]){
				if(j < a) continue;
				segsieve[j-a] = 0;
			}
		}
		for(int i = a ; i <= b; i++){
			if(segsieve[i-a] == 1 and i!=1){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
}