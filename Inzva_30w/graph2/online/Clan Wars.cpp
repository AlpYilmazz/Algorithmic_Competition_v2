#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

vector<vector<int>> adj;

bool bi_check(){
    queue<lli> q;
    vector<bool> visited(adj.size(), false);
    vector<int> color(adj.size(), -1);
    
    for(int i = 1; i < visited.size(); i++){
        if(visited[i]) continue;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
            lli node = q.front();
            q.pop();
            if(visited[node]) continue;
            visited[node] = true;
            for(auto u : adj[node]){
                if(color[u] != -1 && color[u] == color[node]){
                    return false;
                }
                color[u] = (color[node]+1) % 2;
                q.push(u);
            }
        }
    }
    return true;
}

int main() {
    lli i;
    lli n, m;
    lli ni, nj;
    
    cin >> n >> m;
    adj.resize(n+1);
    for(i = 0; i < m; i++){
        cin >> ni >> nj;
        adj[ni].push_back(nj);
        adj[nj].push_back(ni);
    }
    
    if(bi_check()){
        cout << "Fight will be awesome" << endl;
    }
    else{
        cout << "Boring" << endl;
    }
    
    return 0;
}
