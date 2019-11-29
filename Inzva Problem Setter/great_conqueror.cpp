#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

vector<p_ii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> grid;
vector<vector<lli>> visited;

bool is_prime(lli num){
	lli i;
	lli sq = sqrt(num);
	for(i = 2; i <= sq; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

bool is_valid(p_ii c, lli n, lli m){
	return (0 <= c.fi && c.fi < n && 0 <= c.sec && c.sec < m);
}

void dfs(p_ii node){
	visited[node.fi][node.sec] = true;

	for(auto mv : moves){
		p_ii next = {node.fi + mv.fi, node.sec + mv.sec};
		if(is_valid(next, grid.size(), grid[0].size())){
			if(!visited[next.fi][next.sec]
				&& grid[next.fi][next.sec] == '1'){
				dfs(next);
			}
		}
	}
}

lli number_of_cities(){
	lli i, j;
	lli n = grid.size();
	lli m = grid[0].size();
	lli n_city = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(grid[i][j] == '1' && !visited[i][j]){
				n_city++;
				dfs(make_pair(i, j));
			}
		}
	}
	return n_city;
}

int main(){
	lli i, j;
	lli n, m;
	lli n_city;

	cin >> n >> m;
	grid.resize(n);
	visited.resize(n, vector<lli>(m));
	for(i = 0; i < n; i++){
		cin >> grid[i];
	}

	n_city = number_of_cities();

	if(is_prime(n_city)){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}

	cout << n_city << endl;

	return 0;
}

/*
5 5
00001
11011
00000
00110
11001
*/
