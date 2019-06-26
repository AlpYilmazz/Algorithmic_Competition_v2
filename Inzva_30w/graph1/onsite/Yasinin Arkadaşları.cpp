#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100001

int ancestor[N];

void init_ancestors(){
    for(int i = 0; i < N; i++){
        ancestor[i] = i;
    }
}

int find(int k){
    if(ancestor[k] == k) return k;
    return (ancestor[k] = find(ancestor[k]));
}

void Union(int a, int b){
    ancestor[find(a)] = find(b);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    init_ancestors();
    while(m--){
        int a, b;
        int type;
        cin >> type >> a >> b;
        
        if(type == 1){
            Union(a, b);
        }
        else if(type == 2){
            if(find(a) == find(b)){
                printf("Connect\n");
            }
            else{
                printf("Not Connect\n");
            }
        }
    }
    
    return 0;
}
