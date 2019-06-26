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

#define N 2001

p_ii moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int grid[N][N] = {{0}}; // 0 -> not / 1 -> tomato / 2 -> home
vector<vector<bool>> visited;
vector<lli> dist;

void bfs(p_ii inzva, lli n){
	queue<pair<p_ii, lli>> q;
	q.push(make_pair(inzva, 0));
	visited[inzva.first][inzva.second] = true;
	
	while(!q.empty()){
		pair<p_ii, lli> node = q.front();
		q.pop();
		lli node_r = node.first.first;
		lli node_c = node.first.second;
		
		for(auto move : moves){
			lli row = move.first + node_r;
			lli col = move.second + node_c;

			if(row >= 0 && row < n && col >= 0 && col < n){
				if(!visited[row][col] && grid[row][col] != 1){
					if(grid[row][col] == 2){
						dist.push_back(node.second);
					}
					visited[row][col] = true;
					next = make_pair(row, col);
					q.push(make_pair(next, node.second+1));
				}
			}
		}
	}
}

int main(){
	IOS
	lli i;
	lli n, h, g, t;
	lli row, col;
	
	cin >> n >> g >> h >> t;
	visited.resize(n, vector<bool>(n, false));
	for(i = 0; i < g; i++){
		cin >> row >> col;
		grid[row][col] = 1;
	}
	for(i = 0; i < h; i++){
		cin >> row >> col;
		grid[row][col] = 2;
	}
	
	bfs(make_pair(0, 0), n);
	
	for(i = 0; i < t; i++){
		lli d, ans = 0;
		cin >> d;
		
		ans = upper_bound(dist.begin(), dist.end(), d) - dist.begin();
		
		cout << ans << endl;
	}
	
	return 0;
}
