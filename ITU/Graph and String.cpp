#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

vector<set<lli>> adj;
vector<bool> visited;

bool find_Ki(lli node, lli parent){
	visited[node] = true;
	
	if(adj[node].size() != adj[parent].size()){
		return false;
	}
	
	for(auto u : adj[node]){
		if(!(adj[parent].count(u) || u == parent)){
			return false;
		}
	}
	
	for(auto u : adj[node]){
		if(!visited[u]){
			return find_Ki(u, node);
		}
	}
	return true;
}

bool solve(lli node){
	visited[node] = true;
	
	for(auto u : adj[node]){
		if(!visited[u]){
			return find_Ki(u, node);
		}
	}
	return true;
}

int main(){
	IOS
	lli i;
	lli n, m;
	lli u, v;
	
	cin >> n >> m;
	adj.resize(n+1);
	visited.resize(n+1, false);
	for(i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	//debug(bug);
	
	if(!solve(1)){
		cout << "NO" << endl;
		return 0;
	}
	
	//debug(bug);
	
	lli nx = 0;
	bool singleK = false;
	for(nx = 1; nx < visited.size(); nx++){
		if(!visited[nx]){
			break;
		}
		if(nx == visited.size()-1){
			singleK = true;
			break;
		}
	}
	
	//debug(bug);
	
	if(!singleK){
		if(!solve(nx)){
			cout << "NO" << endl;
			return 0;
		}
		
		//debug(bug);
		
		for(i = 1; i < visited.size(); i++){
			if(!visited[i]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	else{
		nx = 0;
	}
	/*else{
		cout << "YES" << endl;
		for(i = 0; i < n; i++){
			cout << "a";
		}
		cout << endl;
	}*/
	
	//debug(bug);
	
	cout << "YES" << endl;
	for(i = 1; i <= n; i++){
		if(i == 1 || adj[1].count(i)){
			cout << "a";
		}
		else if(i == nx || adj[nx].count(i)){
			cout << "c";
		}
	}
	cout << endl;
	
	return 0;
}
