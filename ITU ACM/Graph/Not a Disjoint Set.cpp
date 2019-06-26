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

#define AB 20005

void dfs(int node, int dist, int &odd, int &even, vector<vector<int>> &adj, bool *vis){
	vis[node] = true;
	if(dist&1){
		odd++;
	}
	else{
		even++;
	}
	
	for(auto u : adj[node]){
		if(!vis[u]){
			dfs(u, dist+1, odd, even, adj, vis);
		}
	}
}

int main(){
	IOS
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		bool visited[AB];
		vector<vector<int>> adj(AB);
		set<int> people;
		int i;
		int n, a, b;
		cin >> n;
		for(i = 0; i < n; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			visited[a] = false;
			visited[b] = false;
			people.insert(a);
			people.insert(b);
		}
		
		int ans = 0;
		for(auto p : people){
			int odd = 0, even = 0;
			if(!visited[p]){
				dfs(p, 0, odd, even, adj, visited);
			}
			ans += max(odd, even);
		}
		printf("Case %d: %d\n", ti, ans);
	}
	
	return 0;
}
