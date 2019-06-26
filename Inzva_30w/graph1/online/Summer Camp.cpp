#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 8

vector<pair<int,int>> adj[N+1][N+1];
bool visited[N+1][N+1];
int dist[N+1][N+1];

void rewind(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

int bfs(pair<int,int> node, pair<int,int> target){
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(node.first, node.second, 0));
    visited[node.first][node.second] = true;
    
    while(!q.empty()){
        tuple<int,int,int> t = q.front();
        q.pop();
        visited[get<0>(t)][get<1>(t)] = true;
        
        if(get<0>(t) == target.first && get<1>(t) == target.second) return dist[get<0>(t)][get<1>(t)];
        //cout << dist[get<0>(t)][get<1>(t)] << endl;
        for(auto u : adj[get<0>(t)][get<1>(t)]){
            if(visited[u.first][u.second]) continue;
            dist[u.first][u.second] = dist[get<0>(t)][get<1>(t)] + 1;
            q.push(make_tuple(u.first, u.second, dist[u.first][u.second]));
        }
        //if(get<0>(t) == target.first && get<1>(t) == target.second) return dist[get<0>(t)][get<1>(t)];
    }
    return -1;
}

int main() {
    int i, j;
    int t;
    cin >> t;
    
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            if(i+1 <= N){
                if(j+2 <= N){
                    adj[i][j].push_back(make_pair(i+1, j+2));
                }
                if(j-2 >= 1){
                    adj[i][j].push_back(make_pair(i+1, j-2));
                }
            }
            if(i-1 >= 1){
                if(j+2 <= N){
                    adj[i][j].push_back(make_pair(i-1, j+2));
                }
                if(j-2 >= 1){
                    adj[i][j].push_back(make_pair(i-1, j-2));
                }
            }
            if(i+2 <= N){
                if(j+1 <= N){
                    adj[i][j].push_back(make_pair(i+2, j+1));
                }
                if(j-1 >= 1){
                    adj[i][j].push_back(make_pair(i+2, j-1));
                }
            }
            if(i-2 >= 1){
                if(j+1 <= N){
                    adj[i][j].push_back(make_pair(i-2, j+1));
                }
                if(j-1 >= 1){
                    adj[i][j].push_back(make_pair(i-2, j-1));
                }
            }
        }
    }
    
    while(t--){
        rewind();
        char a[2];
        char b[2];
        scanf("%s %s", a, b);
            
        pair<int,int> from = make_pair(a[0]-'a'+1, a[1]-'1'+1);
        pair<int,int> to = make_pair(b[0]-'a'+1, b[1]-'1'+1);
        //cout << from.first << " " << from.second << endl;
        //cout << from.first << " " << from.second << " -- " << to.first << " " << to.second << " --> ";
        //cout << bfs(from, to) << endl;
        printf("To get from %c%d to %c%d takes %d knight moves.\n", 'a'-1+from.first, from.second,
                                                                'a'-1+to.first, to.second, bfs(from, to));
    }
    /*for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            printf("%c %d:\n", 'a'-1+i, j);
            for(auto u : adj[i][j]){
                printf("\t%c %d\n", 'a'-1+u.first, u.second);
            }
        }
    }*/
    
    
    return 0;
}
