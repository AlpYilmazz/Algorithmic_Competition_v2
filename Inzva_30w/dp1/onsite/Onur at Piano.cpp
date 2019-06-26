#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e7

vector<int> arr;

int main() {
    int i;
    int l, r;
    int total = 0, min_sum = INF, min_i;
    int ni;
    int n, k;
    cin >> n >> k;
    
    arr.push_back(0);
    for(i = 0; i < n; i++){
        cin >> ni;
        arr.push_back(ni);
        if(i < k) total += ni;
    }
    
    l = 1;
    r = k;
    while(r <= n){
        if(total < min_sum){
            total = min_sum;
            min_i = l;
        }
        total -= arr[l];
        l++; r++;
        total += arr[r];
    }
    
    cout << min_i << endl;
    
    return 0;
}
