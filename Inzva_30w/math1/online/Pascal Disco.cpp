#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007

long long int fast_exp(long long int x, long long int k){
    if(k == 0) return 1;
    if(k == 1) return x;
    
    long long int t = fast_exp(x, k>>1);
    
    if((k&1) == 1) return (x * t * t) % mod;
    return (t * t) % mod;
}
//(t%mod)
int main(){
    long long int t, n;
    cin >> t;
    for(int t_i = 0; t_i < t; t_i++){
        cin >> n;
        cout << fast_exp(2, n)-1 << endl;
    }
    
    return 0;
}
