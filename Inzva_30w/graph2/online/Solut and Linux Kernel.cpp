#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

vector<vector<int>> adj;
vector<lli> cmp_time;

lli CompileTime(int n, int target){
    priority_queue<p_ii, vector<p_ii>, greater<p_ii>> pq;
    vector<int> degree(n+1, 0);
    int i;
    
    for(i = 1; i < adj.size(); i++){
        for(auto v : adj[i]){
            degree[v]++;
        }
    }
    
    for(i = 1; i < degree.size(); i++){
        if(degree[i] == 0){
            pq.push(make_pair(cmp_time[i], i));
        }
    }
    
    while(!pq.empty()){
        int node = pq.top().second;
        lli t = pq.top().first;
        pq.pop();
        if(node == target){
            return t;
        }
        for(auto u : adj[node]){
            degree[u]--;
            if(degree[u] == 0){
                if(u == target){
                    return t + cmp_time[u];
                }
                pq.push(make_pair(t + cmp_time[u], u));
            }
        }
    }
    return -1;
}

int main(){
    int i, j;
    int n, m;
    lli ni;
    
    cin >> n >> m;
    cmp_time.resize(n+1);
    adj.resize(n+1);
    for(i = 1; i <= n; i++){
        cin >> ni;
        cmp_time[i] = ni;
    }
    
    for(i = 0; i < n; i++){
        int dep, file, f;
        cin >> dep;
        cin >> file;
        for(j = 0; j < dep; j++){
            cin >> f;
            adj[f].push_back(file);
        }
    }
    
    /*for(i = 1; i < adj.size(); i++){
        cout << i << ":  ";
        for(auto v : adj[i]){
            cout << v << " ";
        }
        cout << endl;
    }*/
    
    cout << CompileTime(n, m) << endl;
    
    return 0;
}
