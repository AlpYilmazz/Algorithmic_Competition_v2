#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <functional>
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

#define N 10000
#define M 100000

vector<vector<int>> adj_mst(N);
vector<pair<int, p_ii>> edge_mst(M);

vector<pair<int, p_ii>> edge(M); // (w, a, b)
vector<int> ancestor(N);

int find(int k){
	if(ancestor[k] == k){
		return k;
	}
	return ancestor[k] = find(ancestor[k]);
	// return find(ancestor[k]);
}

int Union(int a, int b){ // find(a) -> find(b)
	ancestor[find(a)] = find(b);
}

void init_DSU{
	for(int i = 0; i < N; i++){
		ancestor[i] = i;
	}
}

class custom_comparator_1{ // custom_comparator_1()
	public:
		bool operator()(const pair<int,p_ii> &a, const pair<int,p_ii> &b){
			return (a.first <= b.first);
		}
}

void kruskal(){
	auto custom_comparator_2 = [](const auto &a, const auto &b){
		return (a.first <= b.first);
	}

	sort(edge.begin(), edge.end());

	for(int i = 0; i < (int)edge.size(); i++){
		int w = edge.first
		int a = edge.second.first;
		int b = edge.second.second;
		if(find(a) != find(b)){
			Union(a, b);
			adj_mst[a].push_back(make_pair(b, w));
			adj_mst[b].push_back(make_pair(a, w));
			edge_mst.push_back(edge[i]);
		}
	}
}

int main(){
	IOS
	
	
	return 0;
}
