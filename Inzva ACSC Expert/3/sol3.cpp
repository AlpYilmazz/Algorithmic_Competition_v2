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

vector<vector<lli>> adj;
vector<bool> visited;
vector<lli> comp;
bool dp[100005];


lli csize;
void dfs(lli node){
	visited[node] = true;
	csize++;

	for(auto u : adj[node]){
		if(!visited[u]){
			dfs(u);
		}
	}
}

lli knap(){
	dp[0] = 1;

	for(auto x : comp){
		for(int i = (int)1e5; i >= 0; i--){
			if(i < x){
				continue;
			}
			else{
				dp[i] |= dp[i-x];
			}
		}
	}

	lli sum = 0;
	for(int i = 0; i <= (int)1e5; i++){
		sum += dp[i];
	}
	return sum;
}

int main(){
	IOS
	lli i;
	lli n, m;
	lli aj, bj;

	cin >> n >> m;
	adj.resize(n+1);
	visited.resize(n+1, false);
	for(i = 0; i < n; i++){
		cin >> aj >> bj;
		adj[aj].push_back(bj);
		adj[bj].push_back(aj);
	}

	for(i = 1; i <= n; i++){
		if(!visited[i]){
			csize = 0;
			dfs(i);
			comp.push_back(csize);
		}
	}
	
	cout << knap() << endl;
	
	
	return 0;
}
