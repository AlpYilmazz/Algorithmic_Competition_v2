#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;

bool dag_check(){
    int i;
    int result = 0;
    queue<int> q;
    vector<int> degree(adj.size(), 0);
    for(i = 1; i < adj.size(); i++){
        for(auto j : adj[i]){
            degree[j]++;
        }
    }
    for(i = 0; i < degree.size(); i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        result++;
        q.pop();
        for(auto u : adj[node]){
            degree[u]--;
            if(degree[u] == 0){
                q.push(u);
            }
        }
    }
    if(result == adj.size()){
        return true;
    }
    return false;
}

int main(){
    int i;
    int n, m;
    int from, to;
    
    cin >> n >> m;
    adj.resize(n+1);
    for(i = 0; i < m; i++){
        cin >> to >> from;
        adj[from].push_back(to);
    }
    
    if(dag_check()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}
