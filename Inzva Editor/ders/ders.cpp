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

#define fi first
#define sec second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define N 10000

vector<int> ancestor(N);

void init(){
	for(int i = 0; i < N; i++){
		ancestor[i] = i;
	}
}

int find(int node){
	if(ancestor[node] == node){
		return node;
	}
	ancestor[node] = find(ancestor[node]);
	return ancestor[node];
}

void Union(int a, int b){
	ancestor[find(a)] = find(b);
}

vector<vector<pair<int,int>>> adj_mst(N); // adj[a] = (w, b)
vector<pair<int,pair<int,int>>> edge_mst; // (w, (a, b))
vector<pair<int,pair<int,int>>> edge(M); // (w, (a, b))

void kruskal(){
	sort(edge.begin(), edge.end());

	for(int i = 0; i < M; i++){
		int w = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if(find(a) != find(b)){
			Union(a, b);
			edge_mst.push_back(edge[i]);
			adj_mst[a].push_back(make_pair(w,b));
			adj_mst[b].push_back(make_pair(w,a));
		}
	}
}

int main(){
	IOS
	
	
	return 0;
}
