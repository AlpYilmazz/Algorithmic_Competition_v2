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

#define V 105

vector<vector<lli>> adj(V);
vector<vector<lli>> cost(V, vector<lli>(V, 0));

vector<lli> parent(V, -1);

lli source, sink;

bool bfs(){
	vector<bool> visited(V, false);
	queue<lli> q;

	q.push(source);
	visited[source] = true;
	while(!q.empty()){
		lli node = q.front();
		q.pop();
	
		if(node == sink){
			break;
		}
		for(auto u : adj[node]){
			if(cost[node][u] <= 0 || visited[u]){
				continue;
			}
			visited[u] = true;
			parent[u] = node;
			q.push(u);
		}
	}
	return visited[sink];
}

lli max_flow(){
	lli flow = 0;
	while(bfs()){
		lli cur_flow = -1, node = sink;
		while(node != source){
			lli this_flow = cost[parent[node]][node];

			if(cur_flow == -1){
				cur_flow = this_flow;
			}
			else{
				cur_flow = min(cur_flow, this_flow);
			}
		}

		flow += cur_flow;

		node = sink;
		while(node != source){
			cost[parent[node]][node] -= cur_flow;
			cost[node][parent[node]] += cur_flow;

			node = parent[node];
		}
	}

	return flow;
}

int main(){
	IOS
		
	
	return 0;
}
