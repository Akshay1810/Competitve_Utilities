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
    
    g.dfs(1);
    cout<<endl;
}

//for complex cases when node is class not int
class Node{
	public:
	string name;
	list<string> nbrs;
	
	Node(string name){
		this->name = name;
	} 
};

class Graph{
	//all nodes
	//hashmap (String, node*)
	
	unordered_map<string, Node*> umap;
	public:
	Graph(vector<string> cities){
		for(auto it:cities){
			umap[it] = new Node(it);
		}
	}
	
	void addEdge(string x, string y, bool undir = true){
		umap[x] -> nbrs.push_back(y);
		if(undir){
			umap[y] -> nbrs.push_back(x);
		}
	}
	
	void printGraph(){
		for(auto it:umap){
			cout<<it.first<<"-->";
			for(auto it2: umap[it.first]->nbrs){
				cout<<it2<<",";
			}
			cout<<endl;
		}
	}
};

void Solve(){
	vector<string> cities = {"Delhi", "London", "Paris", "New York"};
	Graph g(cities);
	
	g.addEdge("Delhi", "London");
	g.addEdge("New York", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");
	
	g.printGraph();
}