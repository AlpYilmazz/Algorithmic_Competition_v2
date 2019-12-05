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

#define INF 100000000000
#define N 100000

vector<vector<p_ii>> adj(N); // a -> (b, w)
vector<bool> visited(N, false);
vector<int> dist(N, INF);

void solve(){
	priority_queue<p_ii, vector<p_ii>, greater<p_ii>> pq;
	lli start = 0;

	pq.push(make_pair(0, start));
	dist[start] = 0;
	while(!pq.empty()){
		lli node = pq.top().second;
		lli w = pq.top().first;
		pq.pop();

		if(visited[node]) continue;
		visited[node] = true;

		for(auto u : adj[node]){
			if(dist[u.first] > max(w, u.second)){ // dist[u.first] > w + u.second
				dist[u.first] = max(w, u.second);
				pq.push(make_pair(dist[u.first], u.first));
			}
		}
	}
}

int main(){
	IOS
	
	
	return 0;
}
