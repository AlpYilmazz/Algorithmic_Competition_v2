#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

vector<vector<p_ii>> adj;
vector<bool> visited;
vector<lli> ans;
unordered_set<lli> path;
lli k = 1;

void dfs(lli node){

	for(auto u : adj[node]){
		if(!visited[u.first]){
			path.insert(u.first);
			visited[u.first] = true;
			ans[u.second] = 1;
			
			dfs(u.first);
			path.erase(u.first);
		}
		else if(path.count(u.first)){
			ans[u.second] = 2;
			k = 2;
		}
		else{
			ans[u.second] = 1;
		}
	}
}

int main(){
	IOS	
	lli i;
	lli n, m;
	lli u, v;

	cin >> n >> m;
	adj.resize(n+1);
	visited.resize(n+1, false);
	ans.resize(m);
	for(i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(make_pair(v, i));
	}
	
	for(i = 1; i < (lli) visited.size(); i++){
		if(!visited[i]){
			path.insert(i);
			visited[i] = true;
			dfs(i);
			path.erase(i);
		}
	}

	cout << k << endl;
	for(auto ci : ans){
		cout << ci << " ";
	}

	return 0;
}
