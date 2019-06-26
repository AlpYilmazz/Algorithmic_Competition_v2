#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define INF 1e15

vector<vector<pair<lli,lli>>> adj;
vector<lli> gas;
vector<bool> visited;
vector<lli> distance;
priority_queue<lli> pq;

void dfs(lli x){
	
}

int main(){
	IOS
	int i;
	int n, u, v;
	lli wi, c;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> wi;
		gas.push_back(wi);
	}
	for(i = 0; i < n-1; i++){
		cin >> u >> v >> c;
	}
	
	return 0;
}
