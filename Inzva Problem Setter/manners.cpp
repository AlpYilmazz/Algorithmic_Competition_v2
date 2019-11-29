#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

vector<vector<lli>> dag;
vector<lli> indeg;
vector<lli> outdeg;
vector<lli> gen;
vector<lli> candy;

void top_sort(){
	lli i;
	lli n = dag.size()-1;
	queue<lli> q;
	

	for(i = 1; i <= n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		lli node = q.front();
		q.pop();

		for(auto next : dag[node]){
			if(candy[node] == 0){
				candy[next] += gen[node];
			}
			else{
				candy[next] += candy[node];
			}
			indeg[next]--;
			if(indeg[next] == 0){
				q.push(next);
			}
		}
	}
}

int main(){
	lli i;
	lli n, m;

	cin >> n >> m;
	dag.resize(n+1);
	indeg.resize(n+1, 0);
	outdeg.resize(n+1, 0);
	gen.resize(n+1);
	candy.resize(n+1, 0);
	for(i = 1; i <= n; i++){
		cin >> gen[i];
	}
	for(i = 0; i < m; i++){
		lli ai, ak;
		cin >> ai >> ak;
		dag[ai].push_back(ak);
		indeg[ak]++;
		outdeg[ai]++;
	}

	top_sort();
	lli ans = 0;
	for(i = 1; i <= n; i++){
		if(outdeg[i] == 0){
			ans = max(candy[i], ans);
		}
	}
	cout << ans << endl;

	return 0;
}

/*
6 6
1 2 3 4 5 6
1 3
1 5
2 5
3 4
3 5
5 6
*/
