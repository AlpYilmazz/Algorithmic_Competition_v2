#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define N 200001

vector<int> val;
vector<int> adj[N];
int beauty[N] = {0};

int GCD(int n, int m){
	int temp = 0;
	
	while(n != 0){
		temp = n;
		n = m%n;
		m = temp;
	}
	return m;
}

void dfs(int node, int from, int gcd, bool zeroed){
	beauty[node] = max(beauty[node], GCD(val[node], gcd));
	if(zeroed == false){
		beauty[node] = max(beauty[node], gcd);
	}
	
	for(auto u : adj[node]){
		if(u == from) continue;
		if(zeroed == false){
			dfs(u, node, gcd, true);
			dfs(u, node, GCD(val[node], gcd), false);
		}
		else if(zeroed == true){
			dfs(u, node, GCD(val[node], gcd), true);
		}
	}
}

int main(){
	int i;
	int x, y;
	int n, ni;
	
	cin >> n;
	val.resize(n+1);
	for(i = 1; i <= n; i++){
		cin >> ni;
		val[i] = ni;
	}
	
	for(i = 1; i <= n-1; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	beauty[1] = val[1];
	dfs(1, 0, 0, false);
	
	for(i = 1; i <= n; i++){
		cout << beauty[i];
		if(i != n){
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}


