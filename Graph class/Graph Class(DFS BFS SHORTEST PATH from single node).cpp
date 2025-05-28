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
	list<int> *l; //pointer to an array of list
	int V;
	
	public:
		Graph(int v){
			V = v;
			l = new list<int>[V];
		}
		void addEdge(int i, int j, bool undir = true){
			l[i].push_back(j);
			if(undir){
				l[j].push_back(i);
			}
		}
		void printGraph(){
			for(int i = 0 ; i < V; i++){
				cout<<i<<"-->";
				for(auto node:l[i]){
					cout<<node<<",";
				}
				cout<<endl;
			}
		}
		//parent and shortest distance from the node
		//single source shortest path algorithm for undirected graph
		//for finding exact path we can run a ulta while loop from that destination to the source(skipping)
		void bfs(int source){
			queue<int> q;
    		vector<bool> visited(V, false);
    		vector<int> parent(V, -1);
    		vector<int> dist(V,0);
    		q.push(source);
    		visited[source] = true;
    		while(!q.empty()){
    			int ns = q.front();
    			q.pop();
    			cout<<ns<<" ";
    			//push the neighbours of current queue if not visited
    			for(auto it:l[ns]){
    				if(!visited[it]){
    					q.push(it);
    					parent[it] = ns;
    					dist[it] = dist[ns]+1;
    					visited[it] = true;
    				}
    			}
    		}
    		cout<<endl;
    		for(auto it:parent){
    			cout<<it<<" ";
    		}
    		cout<<endl;
    		for(auto it:dist){
    			cout<<it<<" ";
    		}
		}
		
		void dfsHelper(int node, vector<bool> &visited){
			visited[node] = true;
			cout<<node<<" ";
			for(auto it: l[node]){
				if(!visited[it]){
					dfsHelper(it, visited);
				}
			}
		}
		
		void dfs(int source){
			vector<bool> visited(V, false);
			dfsHelper(source, visited);
		}
};

void Solve(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    
    g.printGraph();
    
    g.bfs(1);
    cout<<endl;
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