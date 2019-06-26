#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

typedef long long int lli;

#define debug(x) cout << #x ": " << x << endl

#define N 100001

vector<vector<int>> adj;
vector<lli> val;
vector<bool> visited;

bool dfs(int node){
	stack<int> s;
	
	s.push(node);
	visited[node] = true;
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		for(auto u : adj[temp]){
			if(!visited[u]){
				if(val[temp] != val[u]){
					return false;
				}
				s.push(u);
				visited[u] = true;
			}
		}
	}
	return true;
}

int main(){
	int i;
	int n, u, v;
	lli ci;
	
	cin >> n;
	adj.resize(n+1);
	val.resize(n+1);
	visited.resize(n+1, false);
	for(i = 0; i < n-1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(i = 1; i <= n; i++){
		cin >> ci;
		val[i] = ci;
	}
	
	bool way1, way2;
	for(i = 1; i <= n; i++){
		for(auto h : adj[i]){
			if(val[i] != val[h]){
				visited[i] = true;
				for(auto t : adj[i]){
					way1 = dfs(t);
					if(!way1) break;
				}
				
				if(way1){
					cout << "YES" << endl << i << endl;
					return 0;
				}
				
				visited.clear();
				visited.resize(n+1, false);
				
				visited[h] = true;
				for(auto y : adj[h]){
					way2 = dfs(y);
					if(!way2) break;
				}
				
				if(way2){
					cout << "YES" << endl << h << endl;
					return 0;
				}
				
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl << 1 << endl; // Oh my fucking God
	
	return 0;
}
