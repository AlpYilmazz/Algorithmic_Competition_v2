#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100001
typedef long long int lli;

vector<lli> adj[N];
//vector<int> adj_t[N];
bool visited[N];
vector<lli> pre;
vector<lli> post;

void bothOrder(lli node){
    //cout << node << endl;
    pre.push_back(node);
    visited[node] = true;
    for(auto u : adj[node]){
        if(visited[u]) continue;
        bothOrder(u);
    }
    post.push_back(node);
}

/*void dfs(int node, int prev){
    if(prev != -1){
        adj[prev].push_back(node);
    }
    
    for(auto u : adj_t[node]){
        if(u == prev) continue;
        dfs(u, node);
    }
}*/

void rewind(){
    pre.clear();
    post.clear();
    for(int i = 0; i <= N; i++){
        adj[i].clear();
        //adj_t[i].clear();
        visited[i] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        rewind();
        int i;
        lli n1, n2;
        lli n, r;
        cin >> n >> r;
        for(i = 0; i < n-1; i++){
            cin >> n1 >> n2;
            adj[n1].push_back(n2); //adj_t
            adj[n2].push_back(n1);
        }
        //dfs(r, -1);
        for(i = 1; i <= N; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        bothOrder(r);
        /*// ---------------------------------
        for(i = 0; i < n; i++){
            cout << pre[i] << " ";
        }
        cout << endl;
        for(i = 0; i < n; i++){
            cout << post[i] << " ";
        }
        cout << endl;
        // ---------------------------------*/
        for(i = 0; i < n; i++){
            cout << pre[i] * post[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
