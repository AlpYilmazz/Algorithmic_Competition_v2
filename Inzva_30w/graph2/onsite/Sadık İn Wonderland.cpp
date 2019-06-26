#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000000

typedef long long int lli;
typedef pair<lli,lli> p_ii;
typedef pair<p_ii,lli> p_ii_i;

vector<vector<p_ii>> adj;
vector<bool> visited;
vector<lli> dist;

void Dijkstra(lli n, lli ticket){
    priority_queue< p_ii_i, vector<p_ii_i>, greater<p_ii_i> > pq;

    visited.resize(n+1, false);
    dist.resize(n+1, INF);
    
    dist[1] = 0;
    pq.push(make_pair(make_pair(0, 1), 0));
    
    while(!pq.empty()){
        lli node = pq.top().first.second;
        lli d = pq.top().second;
        pq.pop();
        if(visited[node] || d >= ticket) continue;
        visited[node] = true;
        
        for(auto u : adj[node]){
            lli to = u.first;
            lli w = u.second;
            if(dist[node] + w < dist[to]){
                dist[to] = dist[node] + w;
                pq.push(make_pair(make_pair(dist[to], to), d+1));
            }
        }
    }
}

int main(){
    lli i;
    lli n, m, k;
    lli from, to, time;
    
    cin >> n >> m >> k;
    adj.resize(n+1);
    for(i = 0; i < m; i++){
        cin >> from >> to >> time;
        adj[from].push_back(make_pair(to, time));
    }
    
    Dijkstra(n, k);
    
    for(i = 1; i < dist.size(); i++){
        if(dist[i] == INF){
            cout << -1;
        }
        else{
            cout << dist[i];
        }
        cout << " ";
    }
    
    return 0;
}
