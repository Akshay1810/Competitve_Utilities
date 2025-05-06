#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> nums){
    vector<int> pre(n+1, 0);
    for(int i = 1; i <= n ; i++){
        pre[i] += pre[i-1] + nums[i-1];
    }
    for(int i = 1; i <= n ; i++){
        pre[i]%=n;
    }
    int ans = 0;
    unordered_map<int,int> umap;
    for(int i = 1; i <= n ; i++){
    	// umap[pre[i]]++;
    	if(pre[i] == 0){
    		ans++;
    	}
    	ans += umap[pre[i]];
    	umap[pre[i]]++;
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
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
    	int n;
    	cin>>n;
    	vector<int> v;
    	for(int i = 0 ; i < n ; i++){
    		int x;cin>>x;
    		v.push_back(x);
    	}
        //cout << "Case #" << i << ": ";
        solve(n,v);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}