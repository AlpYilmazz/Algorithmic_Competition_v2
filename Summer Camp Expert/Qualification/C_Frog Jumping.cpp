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

vector<lli> visit;
vector<lli> cost;
queue<lli> q[2];

int main(){
	IOS
	lli i;
	lli n, m, k, d;
	
	cin >> n >> m >> k >> d;
	cost.resize(m);
	visit.resize(k+1);
	for(i = 0; i < m; i++){
		cin >> cost[i];
	}
	for(i = 1; i <= k; i++){
		cin >> visit[i];
	}
	sort(cost.begin(), cost.end());
	sort(visit.begin(), visit.end());
	
	int oldq = 0, newq = 1;
	for(i = visit.size()-1; i >= 1; i--){
		if(visit[i] + d >= n){
			q[oldq].push(visit[i]);
		}
		else{
			break;
		}
	}
	
	for( ; i >= 1; i--){
		while(!q[oldq].empty()){
			if(visit[i] + d >= q[oldq].top()){
				q[newq].push(visit[i]);
				q[oldq].pop();
				break;
			}
			else{
				q[oldq].pop();
			}
		}
		if(q[oldq].empty()){
			int t = oldq;
			oldq = newq;
			newq = t;
		}
	}
	
	while(!q[oldq].empty()){
		if(1 + d >= q[oldq].top()){
			q[newq].push(visit[i]);
			q[oldq].pop();
			break;
		}
	}
	
	
	
	
	return 0;
}
