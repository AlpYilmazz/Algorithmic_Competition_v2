#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

vector<vector<lli>> adj;
vector<lli> edge;

int main(){
	IOS
	lli i;
	lli n, k;
	lli a, b;
	
	cin >> n >> k;
	adj.resize(n+1);
	edge.resize(n+1, 0);
	for(i = 0; i < n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edge[a]++;
		edge[b]++;
	}
	
	return 0;
}
