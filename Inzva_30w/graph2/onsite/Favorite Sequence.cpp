#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000001

typedef long long int lli;

vector<vector<lli>> adj;
vector<lli> degree;
vector<lli> paper;
vector<lli> seq;
priority_queue<lli, vector<lli>, greater<lli>> pq;

void TopologicalSort(){
    lli i;
    for(i = 0; i < degree.size(); i++){
        if(degree[i] == 0){
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        lli node = pq.top();
        pq.pop();
        seq.push_back(node);
        for(auto u : adj[node]){
            degree[u]--;
            if(degree[u] == 0){
                pq.push(u);
            }
        }
    }
}

int main(){
    lli i;
    lli n, k;
    lli num;
    
    cin >> n;
    adj.resize(N);
    degree.resize(N, -1);
    for(lli n_i = 0; n_i < n; n_i++){
        cin >> k;
        for(i = 0; i < k; i++){
            cin >> num;
            paper.push_back(num);
            if(degree[num] == -1){
                degree[num] = 0;
            }
        }
        for(i = 0; i < paper.size()-1; i++){
            adj[paper[i]].push_back(paper[i+1]);
            degree[paper[i+1]]++;
        }
        paper.clear();
    }
    
    TopologicalSort();
    
    for(auto u : seq){
        cout << u << " ";
    }
    
    return 0;
}
