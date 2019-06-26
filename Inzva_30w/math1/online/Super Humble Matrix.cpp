#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

typedef long long int lli;

vector<lli> saved_fac;

lli block(lli i, lli n, lli m){
    if(i < min(n, m)){
        return i;
    }
    if(i >= min(n, m) && i <= max(n, m)){
        return min(n, m);
    }
    if(i > max(n, m)){
        return n + m - i;
    }
    return 0;
}

lli fac(lli n){
    if(n == 1 || n == 0) return 1;
    if(saved_fac[n] != 0) return saved_fac[n];
    
    saved_fac[n] = ((n%mod) * (fac(n-1)%mod)) % mod;
    return saved_fac[n];
}

int main(){
    lli n, m;
    lli ans = 1;
    cin >> n >> m;
    saved_fac.resize(min(n, m)+1, 0);
    for(int i = 1; i <= n+m-1; i++){
        ans *= fac(block(i, n, m));
        ans %= mod;
    }
    cout << ans << endl;
    
    return 0;
}
