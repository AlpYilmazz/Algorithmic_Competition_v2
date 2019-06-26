#include <cmath>
#include <cstdio>
#include <vector>
#include <tuple>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000000

typedef long long int lli;

vector<pair<lli,pair<lli,lli>>> edgeList; // 1(from) --0(w)--> 2(to)

bool DetectNegativeCycle(lli V, lli source){
    lli i, j;
    lli E = edgeList.size();
    vector<lli> dist(V+5, INF);
    dist[source] = 0;
    
    for(i = 1; i <= V-1; i++){
        for(j = 0; j < E; j++){
            lli u = edgeList[j].second.first;
            lli v = edgeList[j].second.second;
            lli wt = edgeList[j].first;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(i = 0; i < E; i++){
        lli u = edgeList[i].second.first;
        lli v = edgeList[i].second.second;
        lli wt = edgeList[i].first;
        if(dist[u] + wt < dist[v]){
            return true;
        }
    }
    return false;
}

int main(){
    lli t;
    
    cin >> t;
    while(t--){
        lli i;
        lli n, m;
        lli u, v, w;
        
        cin >> n >> m;
        
        edgeList.clear();
        if(edgeList.size() != 0){
            while(1){
                cout << "ha";
            }
        }
        for(i = 0; i < m; i++){
            cin >> u >> v >> w;
            edgeList.push_back(make_pair(w, make_pair(u, v)));
        }
        
        bool neg_cyc = DetectNegativeCycle(n, 0);
        if(neg_cyc){
            printf("possible");
        }
        else{
            printf("not possible");
        }
        
        if(t){
            cout << endl;
        }
    }
    
    return 0;
}
