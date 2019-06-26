#include <bits/stdc++.h>

using namespace std;

#define N 1000
#define mod 1000000000

typedef long long int lli;

lli saved[N][N] = {{0}};

lli C(lli n, lli r){
    if(saved[n][r] != 0){
        return (saved[n][r]) % mod;
    }
    
    if(r == n-1 || r == 1){
        saved[n][r] = ((lli) n) % mod;
    }
    else if(n == r || r == 0){
        saved[n][r] = 1LL;
    }
    else{
        saved[n][r] = (C(n-1, r) + C(n-1, r-1)) % mod;
    }
    
    return (saved[n][r]) % mod;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int i;
        lli n;
        cin >> n;
        for(i = 0; i <= n; i++){
            C(n, i);
        }
        for(i = 0; i <= n; i++){
            cout << saved[n][i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
