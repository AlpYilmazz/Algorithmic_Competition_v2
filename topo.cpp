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

vector<vector<lli>> adj;
vector<lli> in_degree;
vector<lli> cmp_time;
vector<lli> timep;

lli CompileTime(lli target){
	queue<lli> q;

	for(lli i = 1; i < (lli)in_degree.size(); i++){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		lli node = q.front();
		q.pop();
		
		if(node == target){
			return timep[node] + cmp_time[node];
		}

		for(auto u : adj[node]){
			timep[u] = max(timep[u], timep[node] + cmp_time[node]);
			
			in_degree[u]--;
			if(in_degree[u] == 0){
				q.push(u);
			}
		}
	}
	return -1;
}

int main(){
	IOS
    int i, j;
    int n, m;
    lli ni;
    
    cin >> n >> m;
    adj.resize(n+1);
	in_degree.resize(n+1);
	cmp_time.resize(n+1);
	timep.resize(n+1);
    for(i = 1; i <= n; i++){
        cin >> ni;
        cmp_time[i] = ni;
    }
    
    for(i = 0; i < n; i++){
        int dep, file, f;
        cin >> dep;
        cin >> file;
		in_degree[file] = dep;
        for(j = 0; j < dep; j++){
            cin >> f;
            adj[f].push_back(file);
        }
    }

    cout << CompileTime(m) << endl;
    
    return 0;
}
