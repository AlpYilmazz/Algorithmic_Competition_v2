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

vector<vector<int>> adj(N); // dag
vector<int> in_degree(N);
vector<int> out_degree(N);

vector<int> top_sort;

void topological_sort(){
	queue<int> q;

	for(int i = 0; i < N; i++){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		top_sort.push_back(node);

		for(auto u : adj[node]){
			in_degree[u]--;
			if(in_degree[u] == 0){
				q.push(u);
			}
		}
	}
}

int main(){
	IOS
	
	
	return 0;
}
