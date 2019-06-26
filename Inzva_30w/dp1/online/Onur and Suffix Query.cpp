#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int i;
    int ni;
    int n, m;
    vector<int> arr;
    unordered_set<int> t_set;
    vector<int> distinct;
    
    cin >> n >> m;
    arr.push_back(0);
    for(i = 1; i <= n; i++){
        cin >> ni;
        arr.push_back(ni);
    }
    distinct.resize(n+1);
    for(i = n; i >= 1; i--){
        t_set.insert(arr[i]);
        distinct[i] = t_set.size();
    }
    
    while(m--){
        int li;
        cin >> li;
        cout << distinct[li] << endl;;
    }
    
    return 0;
}
