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
class Graph{
	vector<pair<int,int>> *l;
	int V;
	public:
	Graph(int n){
		V =n;
		l = new vector<pair<int,int>> [n];
	}
	
	void addEdge(int x, int y, int w){
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}
	
	int prim_mst(){
		//weight , to
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		//another array which stores a node has been included in MST or not.
		bool *visited = new bool[V]{0};
		int ans  = 0;
		
		//begin
		pq.push({0,0}); //weight,node
		while(!pq.empty()){
			//pick out the edge with the minimum weight
			auto best = pq.top();
			pq.pop();
			
			int to = best.second;
			int weight = best.first;
			
			if(!visited[to]){
				ans += weight;
				visited[to] = 1;
				//add the new edges to queue
				for(auto x:l[to]){
					if(visited[x.first] == 0){
						pq.push({x.second, x.first});
					}
				}
			}
		}
		
		return ans;
	}
};

void Solve(){
	int n,m;
	cin>>n>>m;
	
    Graph g(n);
    for(int i = 0 ; i < m ; i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	g.addEdge(x-1,y-1,w);
    }
    cout<<g.prim_mst()<<endl;
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