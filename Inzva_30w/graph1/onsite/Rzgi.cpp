#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1001

typedef long long int lli;

vector<lli> leaf; // node # of leaf
vector<int> adj[N];
pair<double,lli> edge[N][N]; // edge[from][to] = {percent, super}
lli parent[N];
double litre[N];

void init_all(){
    for(int i = 0; i < N; i++){
        parent[i] = -1;
        litre[i] = 0.0;
        for(int j = 0; j < N; j++){
            edge[i][j] = make_pair(-1, -1);
        }
    }
}

void dfs(int node, int prev){
    parent[node] = prev;
    
    for(auto u : adj[node]){
        if(u == prev) continue;
        dfs(u, node);
    }
}

int main(){
    lli i;
    float ki;
    lli ai, bi, xi, ti;
    lli n;
    cin >> n;
    
    init_all();
    for(i = 1; i <= n-1; i++){
        cin >> ai >> bi >> xi >> ti;
        edge[ai][bi] = make_pair((float)xi, ti);
        edge[bi][ai] = make_pair((float)xi, ti);
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
        //parent[bi] = ai;
    }
    dfs(1, -1);
    for(i = 1; i <= n; i++){
        cin >> ki;
        if(ki != -1.0){
            leaf.push_back(i);
            litre[i] = ki;
        }
    }
    
    int c;
    double liq;
    for(auto u : leaf){
        c = u;
        while(parent[c] != -1){
            liq = litre[c];
            if(edge[parent[c]][c].second == 1){
                liq = sqrt(liq);
            }
            liq *= (100.0 / edge[parent[c]][c].first);
            litre[parent[c]] = max(litre[parent[c]], liq);
            c = parent[c];
        }
    }
    
    printf("%.4f\n", litre[1]);
    
    
    return 0;
}
