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

#define INF 300

vector<lli> snow;
vector<lli> bL;
vector<lli> bS;
bool visited[250][250];

lli min_boots = INF;
void state_dfs(lli tile, lli boot, lli n){
	if(visited[tile][boot]) return;
	visited[tile][boot] = true;
	
	if(tile == n-1){
		min_boots = min(boot, min_boots);
		return;
	}
	
	for(lli t_i = tile+1; t_i < n && t_i - tile <= bS[boot]; t_i++){
		if(snow[t_i] <= bL[boot]){
			state_dfs(t_i, boot, n);
		}
	}
	for(lli b_i = boot+1; b_i < (lli)bS.size(); b_i++){
		if(snow[tile] <= bL[b_i]){
			state_dfs(tile, b_i, n);
		}
	}
}

int main(){
	IOS
	lli i;
	lli n, b;
	
	cin >> n >> b;
	snow.resize(n);
	bL.resize(b);
	bS.resize(b);
	
	for(i = 0; i < n; i++){
		cin >> snow[i];
	}
	for(i = 0; i < b; i++){
		cin >> bL[i] >> bS[i];
	}
	
	state_dfs(0, 0, n);
	
	cout << min_boots << endl;
	
	return 0;
}
