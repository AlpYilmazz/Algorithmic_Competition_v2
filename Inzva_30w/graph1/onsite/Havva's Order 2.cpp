#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 10007

vector<int> adj[N];
vector<bool> visited;
vector<int> pre;
vector<int> post;

/*void clear_vis(){
    for(i = 0; i < N; i++){
        visited[i] = false;
    }
    visited[1] = true;
}*/

void rewind(){
    visited.clear();
    pre.clear();
    post.clear();
    for(int i = 0; i < N; i++){
        adj[i].clear();
    }
}

void preOrder(int node){
    visited[node] = true;
    
    pre.push_back(node);
    for(auto u : adj[node]){
        if(visited[u]) continue;
        preOrder(u);
    }
}

void postOrder(int node){
    visited[node] = true;
    
    for(auto u : adj[node]){
        if(visited[u]) continue;
        postOrder(u);
    }
    post.push_back(node);
    //cout << node << endl;
}

/*void dfs(int node, int prev){
    for(auto u : adj[node]){
        if(visited[u]) continue;
        dfs(u, node);
    }
}*/

int main() {
    int t;
    cin >> t;
    while(t--){
        rewind();
        int i;
        int n, n1, n2;
        cin >> n;
        
        for(i = 0; i < n-1; i++){
            cin >> n1 >> n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        for(i = 1; i <= n; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        /*for(i = 1; i <= n; i++){
            cout << i << ":\n";
            for(auto u : adj[i]){
                cout << "\t" << u << endl;
            }
        }*/
        visited.resize(n+1, false);
        visited[1] = true;
        preOrder(adj[1][0]);
        visited.clear();
        visited.resize(n+1, false);
        visited[1] = true;
        postOrder(adj[1][1]);
        
        for(i = 0; i < pre.size(); i++){
            cout << pre[i] << " ";
        }
        cout << 1 << " ";
        for(i = 0; i < post.size(); i++){
            cout << post[i] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
