#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main(){
    int i, j;
    lli tm;
    lli n, m;
    cin >> n >> m;
    
    priority_queue<pair<lli,lli>> pq;  // total time, kasa_i
    vector<lli> kasa;
    vector<lli> human;
    
    for(i = 0; i < n; i++){
        cin >> tm;
        kasa.push_back(tm);
    }
    for(i = 0; i < m; i++){
        cin >> tm;
        human.push_back(tm);
    }
    
    j = 0;
    pair<lli,lli> t;
    for(i = 0; i < human.size(); i++){
        if(pq.size() < kasa.size()){
            pq.push(make_pair(-(kasa[j]*human[i]), -j));
            j++;
        }
        else{
            t = pq.top();
            pq.pop();
            pq.push(make_pair(-(kasa[-t.second]*human[i]) + t.first, t.second));
        }
    }
    
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
    }
    cout << -t.first << endl;
    
    return 0;
}
