#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

vector<p_ii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> grid; // 0: tree / 1: jedi / 2: sith
lli min_time = 0;

bool is_valid(p_ii c, lli n, lli m){
	return (0 <= c.fi && c.fi < n && 0 <= c.sec && c.sec < m);
}

void bfs(){
	lli i, j;
	lli n = (lli)grid.size();
	lli m = (lli)grid[0].size();
	queue<p_ii> q;

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(grid[i][j] == 2){
				q.push(make_pair(i, j));
			}
		}
	}
	q.push(make_pair(-1, -1)); // end flag

	while(!q.empty()){
		bool flag = false;

		while(!(q.front().fi == -1 && q.front().sec == -1)){
			p_ii node = q.front();
			q.pop();
			
			for(auto mv : moves){
				p_ii adj = {node.fi + mv.fi, node.sec + mv.sec} ;
				if(is_valid(adj, n, m) && grid[adj.fi][adj.sec] == 1){
					q.push(make_pair(adj.fi, adj.sec));
					grid[adj.fi][adj.sec] = 2;
					flag = true;
				}
			}
		}
		if(flag){
			min_time++;
		}

		q.pop(); // pop the end flag

		if(!q.empty()){
			q.push(make_pair(-1, -1));
		}
	}
}

int main(){
	lli i, j;
	lli n, m;

	cin >> n >> m;
	grid.resize(n, vector<int>(m, 0));
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}

	bfs();

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(grid[i][j] == 1){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << min_time << endl;
	

	return 0;
}

/*
5 5
0 0 0 0 2
0 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 1 1 1 1
*/
