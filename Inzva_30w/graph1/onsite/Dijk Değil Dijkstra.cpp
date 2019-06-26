#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 101

vector<int> adj[N];
bool visited[N];

void rewind(){
    for(int i = 0; i < N; i++){
        adj[i].clear();
        visited[i] = false;
    }
}

int bfs(int start, int target){
    queue<pair<int,int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    
    while(!q.empty()){
        pair<int,int> t = q.front();
        q.pop();
        
        if(t.first == target) return t.second;
        
        for(auto u : adj[t.first]){
            if(visited[u]) continue;
            q.push(make_pair(u, t.second+1));
            visited[u] = true;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        rewind();
        int i;
        int ans;
        int from, to;
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        
        for(i = 0; i < m; i++){
            cin >> from >> to;
            adj[from].push_back(to);
        }
        ans = bfs(a, b);
        if(ans == -1){
            cout << "No Path!" << endl;
        }
        else{
            cout << ans << endl;
        }
        if(t){
            cout << "--" << endl;
        }
    }
    
    return 0;
}
