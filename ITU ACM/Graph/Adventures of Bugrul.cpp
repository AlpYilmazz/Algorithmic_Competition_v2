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
#include <tuple>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

vector<vector<lli>> adj;
vector<bool> reach;
vector<lli> tra_children;
lli roads = 0;

void dfs(lli node, lli parent, lli dist){
	if(dist <= 2){
		reach[node] = true;
	}
	
	for(auto u : adj[node]){
		if(u != parent){
			dfs(u, node, dist+1);
		}
	}
	
	if(!reach[node]){
		reach[parent] = true;
		for(auto v : adj[parent]){
			reach[v] = true;
		}
		roads++;
	}
}

void iter_dfs(){
	stack<tuple<lli, lli, lli>> s;
	s.push(make_tuple(s, -1, 0));
	
	while(!s.empty()){
		tuple<lli, lli, lli> temp = s.top();
		lli node = get<0>(temp);
		lli parent = get<1>(temp);
		lli dist = get<2>(temp);
		
		for(auto u : adj[node]){
			if(u != parent){
				tra_children
				s.push(make_tuple(u, node, dist+1));
			}
		}
	}
}

int main(){
	IOS
	lli i;
	lli n, cost;
	lli u, v;
	
	//cin >> n >> cost;
	n = 100000; cost = 1; u = 1; v = 2;
	adj.resize(n+1);
	reach.resize(n+1, false);
	tra_children(n+1, 0);
	for(i = 0; i < n-1; i++){
		//cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		//cout << u << " " << v << endl;
		u++; v++;
	}
	
	dfs(1, 1, 0);
	
	cout << "algo: " << cost * roads << endl;
	cout << "linear: " << ((n-3) / 3) + 1 << endl;
	
	return 0;
}
