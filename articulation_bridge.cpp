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

#define V 100005

vector<vector<lli>> adj;
vector<lli> dep(V);
vector<bool> visited(V, false);

vector<p_ii> bridge;
vector<lli> articulation;


lli find_bridge(lli node, lli parent, lli depth){
	lli min_depth = depth;
	dep[node] = depth;
	visited[node] = true;
	
	for(auto u : adj[node]){
		if(u == parent){
			continue;
		}

		if(visited[u]){
			min_depth = min(min_depth, dep[u]);
			continue;
		}

		lli subtree_dep = find_bridge(u, node, depth+1);
		if(subtree_dep >= depth+1){
			bridge.push_back(make_pair(node, u));
		}

		min_depth = min(min_depth, subtree_depth);
	}

	return min_depth;
}

lli find_articulation(lli node, lli parent, lli depth){
	lli min_depth = depth, children = 0;
	dep[node] = depth;
	visited[node] = true;
	
	for(auto u : adj[node]){
		if(u == parent){
			continue;
		}

		if(visited[u]){
			min_depth = min(min_depth, dep[u]);
			continue;
		}

		lli subtree_dep = find_articulation(u, node, depth+1);
		if(subtree_dep >= depth && parent != -1){
			articulation.push_back(node);
		}

		min_depth = min(min_depth, subtree_dep);
		children++;
	}
	if(parent == -1 && children >= 2){
		articulation.push_back(node);
	}

	return min_depth;
}

int main(){
	IOS
	
	
	return 0;
}
