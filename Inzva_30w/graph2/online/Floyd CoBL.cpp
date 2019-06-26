#include <bits/stdc++.h>

using namespace std;

#define N 401
#define INF 10000000000

typedef long long int lli;

lli graph[N][N] = {{0}}; // graph[from][to] = weight
lli dist[N][N] = {{0}};

void init_all(int V){
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(i != j && graph[i][j] == 0){
                graph[i][j] = INF;
            }
            dist[i][j] = graph[i][j];
        }
    }
}

void FloydWarshall(int V){
    init_all(V);
    int i, j, k;
    
    for(k = 1; k <= V; k++){
        for(i = 1; i <= V; i++){
            for(j = 1; j <= V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    int i;
    lli n, m;
    lli x, y, r;
    
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> x >> y >> r;
        graph[x][y] = r;
    }
    
    FloydWarshall(n);
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == INF){
            cout << -1 << endl;
        }
        else{
            cout << dist[a][b] << endl;
        }
    }
    
    
    return 0;
}
