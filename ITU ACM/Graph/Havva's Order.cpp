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

vector<vector<lli>> adj;
vector<lli> pre;
vector<lli> post;

void rewind(){
	adj.clear();
	pre.clear();
	post.clear();
}

void dfs(lli node, lli parent){
	pre.push_back(node);
	
	for(auto u : adj[node]){
		if(u != parent){
			dfs(u, node);
		}
	}
	
	post.push_back(node);
}

int main(){
	IOS
	lli t;
	
	cin >> t;
	
	while(t--){
		lli i;
		lli n, root;
		lli ni, nj;
		
		cin >> n >> root;
		adj.resize(n+1);
		for(i = 0; i < n-1; i++){
			cin >> ni >> nj;
			adj[ni].push_back(nj);
			adj[nj].push_back(ni);
		}
		
		for(i = 1; i <= n; i++){
			sort(adj[i].begin(), adj[i].end());
		}
		
		dfs(root, -1);
		
		for(i = 0; i < n; i++){
			cout << pre[i] * post[i] << " ";
		}
		cout << endl;
		
		rewind();
	}
	
	return 0;
}
