#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

vector<vector<p_ii>> adj; // node, w

lli prim(lli goal){
    vector<bool> visited(adj.size(), false);
    priority_queue< p_ii, vector<p_ii>, greater<p_ii> > pq;
    lli cost = 0, total_nodes = 0;
    
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        lli node = pq.top().second;
        lli w = pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        total_nodes++;
        cost += w;
        if(total_nodes == goal){
            break;
        }
        
        for(auto u : adj[node]){
            pq.push(make_pair(u.second, u.first));
        }
    }
    
    return cost;
}

int main(){
    lli i;
    lli n, m, k;
    lli u, v, w;
    
    cin >> n >> m >> k;
    adj.resize(n+1);
    for(i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    cout << prim(k) << endl;
    
    return 0;
}
