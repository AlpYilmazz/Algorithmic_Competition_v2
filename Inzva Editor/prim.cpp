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

#define fi first
#define sec second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define N 10000

vector<vector<p_ii>> adj_mst(N); // a -> (b, w)

vector<vector<p_ii>> adj(N); // a -> (b, w)
vector<bool> visited(N, false); // added to mst

void prim(){
    priority_queue<pair<lli,p_ii>, vector<pair<int,p_ii>>, greater<pair<lli,p_ii>>> pq; // (w, (from, to))
    lli start = 0;
    
    pq.push(make_pair(0, make_pair(-1, start)));
    while(!pq.empty()){
        lli from = pq.top().second.first;
        lli node = pq.top().second.second;
        lli w = pq.top().first;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;
        
        if(from != -1){
            adj_mst[from].push_back(make_pair(node, w));
            adj_mst[node].push_back(make_pair(from, w));
        }

        for(auto u : adj[node]){ // u: (to, w)
            pq.push(make_pair(u.second, make_pair(node, u.first)));
        }
    }
}

int main(){
	IOS
	
	
	return 0;
}
