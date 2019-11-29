#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define N 10000

vector<vector<int>> adj(N);
vector<bool> visited(N);
vector<int> color(N, -1);

bool bipartite_check(){
    queue<int> q;
    int start = 1;
    
    color[start] = 0;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
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
    return true;
}

int main(){
	IOS
	
	
	return 0;
}
