#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 5000001

vector<int> adj[N];
bool visited[N];
int visited_nodes = 0;

void dfs(int x){
    visited[x] = true;
    visited_nodes++;
    for(auto u : adj[x]){
        if(visited[u]) continue;
        dfs(u);
    }
}

int main(){
    int n, m;
    int n1, n2;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    dfs(n1);
    
    if(visited_nodes == n){
        cout << "Connected" << endl;
    }
    else{
        cout << "Not Connected" << endl;
    }
    
    return 0;
}
