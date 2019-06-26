#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100001

typedef long long int lli;

lli tree[4*(N)] = {0};
vector<lli> arr;

void build(lli ind, lli l, lli r){
    if(l == r){
        tree[ind] = arr[l];
    }
    else{
        lli mid = (l+r) / 2;
        build(ind*2, l, mid);
        build(ind*2 + 1, mid+1, r);
        tree[ind] = tree[ind*2] + tree[ind*2 + 1];
    }
}

lli query(lli ind, lli l, lli r, lli lw, lli rw){
    if(r < lw || rw < l){
        return 0;
    }
    if(lw <= l && r <= rw){
        return tree[ind];
    }
    lli mid = (l+r) / 2;
    
    return query(ind*2, l, mid, lw, rw) + query(ind*2 + 1, mid+1, r, lw, rw);
}

void update(lli ind, lli l, lli r, lli x, lli val){
    if(x < l || r < x){
        return;
    }
    if(l == x && r == x){
        tree[ind] = val;
        return;
    }
    lli mid = (l+r) / 2;
    
    update(ind*2, l, mid, x, val);
    update(ind*2 + 1, mid+1, r, x, val);
    tree[ind] = tree[ind*2] + tree[ind*2 + 1];
}
               
int main() {
    lli i;
    lli n, q;
    
    cin >> n >> q;
    arr.resize(n+1);
    for(i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build(1, 1, n);
    
    while(q--){
        lli type, a, b;
        cin >> type >> a >> b;
        if(type == 1){
            cout << query(1, 1, n, a, b) << endl;
        }
        else{
            update(1, 1, n, a, b);
        }
    }
    
    return 0;
}
