#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <tuple>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

#define N 251
#define INF 1000000

vector<string> harita; // x & . , broken?
//bool visited[N][N]; // 1 index
int dist[N][N];

void rewind(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            //visited[i][j] = false;
            dist[i][j] = INF;
        }
    }
}

int bfs(pair<int,int> start, pair<int,int> end, int bomb, int n){
	queue<tuple<int,int,int,int,int>> q; // row, col, step, bomb, ~parent
	q.push(make_tuple(start.first, start.second, 0, 0, 'n'));
	
	//visited[start.first][start.second] = true;
	
	while(!q.empty()){
		tuple<int,int,int,int,int> t = q.front();
		q.pop();
		
		//visited[get<0>(t)][get<1>(t)] = true;
		
		/*
		if(get<0>(t) == end.first && get<1>(t) == end.second){
			return dist[get<0>(t)][get<1>(t)];
		}
		*/
		
		// RECURSION BELOW
		// && harita[get<0>(t)-1][].second == false
		
		if(get<0>(t)-1 >= 1 && get<4>(t) != 'L'){
			if(harita[get<0>(t)-1][get<1>(t)] == 'x'
				&& get<3>(t) < bomb){
					
				dist[get<0>(t)-1][get<1>(t)] 
					= min(dist[get<0>(t)-1][get<1>(t)], dist[get<0>(t)][get<1>(t)] + 1);
				
				q.push(make_tuple(get<0>(t)-1
								, get<1>(t)
								, get<2>(t)+1
								, get<3>(t)+1
								, 'R'));
			}
			else if(harita[get<0>(t)-1][get<1>(t)] == '.'){
				
				dist[get<0>(t)-1][get<1>(t)] 
					= min(dist[get<0>(t)-1][get<1>(t)], dist[get<0>(t)][get<1>(t)] + 1);
				
				q.push(make_tuple(get<0>(t)-1
								, get<1>(t)
								, get<2>(t)+1
								, get<3>(t)
								, 'R'));
			}
		}
		
		if(get<0>(t)+1 <= n && get<4>(t) != 'R'){
			if(harita[get<0>(t)+1][get<1>(t)] == 'x'
				&& get<3>(t) < bomb){
					
				dist[get<0>(t)+1][get<1>(t)] 
					= min(dist[get<0>(t)+1][get<1>(t)], dist[get<0>(t)][get<1>(t)] + 1);
					
				q.push(make_tuple(get<0>(t)+1
								, get<1>(t)
								, get<2>(t)+1
								, get<3>(t)+1
								, 'L'));
			}
			else if(harita[get<0>(t)+1][get<1>(t)] == '.'){
				
				dist[get<0>(t)+1][get<1>(t)] 
					= min(dist[get<0>(t)+1][get<1>(t)], dist[get<0>(t)][get<1>(t)] + 1);
				
				q.push(make_tuple(get<0>(t)+1
								, get<1>(t)
								, get<2>(t)+1
								, get<3>(t)
								, 'L'));
			}
		}		
		
		if(get<1>(t)-1 >= 1 && get<4>(t) != 'U'){
			if(harita[get<0>(t)][get<1>(t)-1] == 'x'
				&& get<3>(t) < bomb){
					
				dist[get<0>(t)][get<1>(t)-1] 
					= min(dist[get<0>(t)][get<1>(t)-1], dist[get<0>(t)][get<1>(t)] + 1);
					
				q.push(make_tuple(get<0>(t)
								, get<1>(t)-1
								, get<2>(t)+1
								, get<3>(t)+1
								, 'D'));
			}
			else if(harita[get<0>(t)][get<1>(t)-1] == '.'){					
				
				dist[get<0>(t)][get<1>(t)-1] 
					= min(dist[get<0>(t)][get<1>(t)-1], dist[get<0>(t)][get<1>(t)] + 1);
				
				q.push(make_tuple(get<0>(t)
								, get<1>(t)-1
								, get<2>(t)+1
								, get<3>(t)
								, 'D'));
			}
		}
		
		if(get<1>(t)+1 <= n && get<4>(t) != 'D'){
			if(harita[get<0>(t)][get<1>(t)+1] == 'x'
				&& get<3>(t) < bomb){
					
				dist[get<0>(t)][get<1>(t)+1] 
					= min(dist[get<0>(t)][get<1>(t)+1], dist[get<0>(t)][get<1>(t)] + 1);
					
				q.push(make_tuple(get<0>(t)
								, get<1>(t)+1
								, get<2>(t)+1
								, get<3>(t)+1
								, 'U'));
			}
			else if(harita[get<0>(t)][get<1>(t)+1] == '.'){
				
				dist[get<0>(t)][get<1>(t)+1] 
					= min(dist[get<0>(t)][get<1>(t)+1], dist[get<0>(t)][get<1>(t)] + 1);
				
				q.push(make_tuple(get<0>(t)
								, get<1>(t)+1
								, get<2>(t)+1
								, get<3>(t)
								, 'U'));
			}
		}
	}
	
	return dist[end.first][end.second];
}

int main(){
	IOS
	int i;
	int n, m;
	int ri, ci, rf, cf;
	
	cin >> n >> m >> ri >> ci >> rf >> cf;
	
	harita.resize(n+1);
	for(i = 1; i <= n; i++){
		string s;
		cin >> s;
		harita[i] = s;
	}
	ri++; ci++; rf++; cf++;
	
	rewind();
	int ans = bfs(make_pair(ri, ci), make_pair(rf, cf), m, n);
	
	if(ans == INF){
		cout << "Impossible" << endl;
	}
	else{
		cout << ans << endl;
	}
	
	return 0;
}
