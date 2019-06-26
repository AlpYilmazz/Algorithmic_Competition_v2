#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int i;
    int l, r, u, d;
    char ni;
    int n;
    cin >> n;
    
    l = r = u = d = 0;
    for(i = 0; i < n; i++){
        cin >> ni;
        if(ni == 'L') l++;
        else if(ni == 'R') r++;
        else if(ni == 'U') u++;
        else if(ni == 'D') d++;
    }
    cout << 2*min(l, r) + 2*min(u, d) << endl;
    
    return 0;
}
