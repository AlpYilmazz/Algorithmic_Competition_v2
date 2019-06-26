#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
	visited[node] = true;
	
	for(auto u : adj[node]){
		if(!visited[u]){
			visited[u] = true;
			dfs(u);
		}
	}
}

int main(){
	IOS
	int i;
	int n, m;
	int mi, mj;
	
	cin >> n >> m;
	adj.resize(n+1);
	visited.resize(n+1, false);
	for(i = 0; i < m; i++){
		cin >> mi >> mj;
		adj[mi].push_back(mj);
		adj[mj].push_back(mi);
	}
	
	dfs(1);
	
	for(i = 1; i <= n; i++){
		if(!visited[i]){
			cout << "Not Connected" << endl;
			return 0;
		}
	}
	cout << "Connected" << endl;
	
	return 0;
}
