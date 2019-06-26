#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<vector<int>> adj;
vector<bool> visited;
vector<int> degree;

bool dfs(int node, bool prev){
	int deg = degree[node];
	if(prev) deg--;
	
	bool final = (deg+1)%2;
	bool step = true;
	for(auto u : adj[node]){
		if(visited[u]) continue;
		visited[u] = true;
		step = dfs(u, (deg+1)%2);
		final |= step;
	}
	return final;
}

int main(){
	IOS
	int i;
	int n;
	int pi;
	
	cin >> n;
	adj.resize(n+1);
	visited.resize(n+1, false);
	degree.resize(n+1, 0);
	for(i = 1; i <= n; i++){
		cin >> pi;
		if(pi == 0) continue;
		adj[i].push_back(pi);
		adj[pi].push_back(i);
		degree[i]++;
		degree[pi]++;
	}
	
	bool ans;
	ans = dfs(1, false);
	
	if(ans){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}
