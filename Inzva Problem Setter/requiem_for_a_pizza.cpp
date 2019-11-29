#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

#define INF 1000000000000

vector<vector<lli>> adj;
vector<bool> visited;
vector<lli> price;
lli min_money = INF;

void bfs(lli house, lli L, lli R){
	queue<p_ii> q; // node, dist

	visited[house] = true;
	q.push(make_pair(house, 0));
	
	while(!q.empty()){
		p_ii node = q.front();
		q.pop();

		if(node.sec >= L){
			min_money = min(price[node.fi], min_money);
		}
		if(node.sec >= R){
			continue;
		}

		for(auto u : adj[node.fi]){
			if(!visited[u]){
				visited[u] = true;
				q.push(make_pair(u, node.sec+1));
			}
		}
	}
	
}

int main(){
	lli i;
	lli n, m, h;
	lli l, r;

	cin >> n >> m >> h;
	cin >> l >> r;
	adj.resize(n+1);
	visited.resize(n+1);
	price.resize(n+1);
	for(i = 1; i <= n; i++){
		cin >> price[i];
	}
	for(i = 0; i < m; i++){
		lli a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(h, l, r);

	if(min_money == INF){
		cout << -1 << endl;
	}
	else{
		cout << min_money << endl;
	}


	return 0;
}

/*
7 8 1
2 3
1 9 1 4 1 6 1
1 3
1 5
2 7
3 4
3 6
3 5
5 6
6 2
*/
