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
vector<int> sub;
int main_root = 1;

lli C(lli n, lli r){
	// C(n, 1)
	if(r == 1) return n;
	// C(n, 2)
	return (n * (n-1)) / 2;
}

lli solve(int root, int p){
	lli i, j, k;
	lli ans = 0;
	lli n = (lli)adj.size()-1;
	lli sz = (lli)adj[root].size();
	for(i = 0; i < sz && i != p; i++){
		for(j = 0; j < sz && j != i; j++){
			for(k = 0; k < sz && k != i && k != j; k++){
				lli Ai = sub[adj[root][i]];
				lli Aj = sub[adj[root][j]];
				lli Ak = sub[adj[root][k]];
				if(adj[root][i] == p) Ai = n - sub[root];
				if(adj[root][j] == p) Aj = n - sub[root];
				if(adj[root][k] == p) Ak = n - sub[root];
				ans += 4 * (Ai+1) * (Aj+1) * C(Ak, 2);
				ans -= 4 * C(Ak, 2);
			}
		}
	}

	for(i = 0; i < sz; i++){
		for(j = 0; j < sz && j != i; j++){
			lli Ai = sub[adj[root][i]];
			lli Aj = sub[adj[root][j]];
			if(adj[root][i] == p) Ai = n - sub[root];
			if(adj[root][j] == p) Aj = n - sub[root];
			ans += 4 * C(Ai, 2) * C(Aj, 2);
			ans += 4 * C(Ai, 1) * C(Aj, 2);
			ans += 4 * C(Ai, 2) * C(Aj, 1);
		}
	}

	debug(ans);
	for(i = 0; i < sz; i++){
		if(adj[root][i] == p) continue;
		ans += solve(adj[root][i], root);
	}
		

	return ans;
}

int nsubt(int node){
	if(node == main_root) return (int)adj[node].size();
	return (int)adj[node].size()-1;
}

int dfs(int node, int p){
	
	for(auto u : adj[node]){
		if(u != p){
			sub[node] += dfs(u, node);
		}
	}
	sub[node]++;
	return sub[node];
}

/*
4
1 2
2 3
3 4
*/

int main(){
	IOS
	lli i;
	int n;

	cin >> n;
	adj.resize(n+1);
	sub.resize(n+1, 0);
	for(i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(main_root, -1);
	
	cout << solve(main_root, -1) << endl;

	return 0;
}
