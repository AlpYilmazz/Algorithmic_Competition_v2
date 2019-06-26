#include <bits/stdc++.h>

using namespace std;

vector<int> facx;

int gcd(int a, int b){
    /*if(a == 0) return b;
    return gcd(b%a, a);
    */
    int temp;
    while(a != 0){
        temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

int main(){
    int i;
    int x;
    int n, k, t, l;
    cin >> n >> k;
    for(i = 0; i < n; i++){
        //cin >> t;
        scanf("%d", &t);
        if(i == 0) x = t;
        x = gcd(x, t);
    }
    
    for(i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            facx.push_back(i);
            facx.push_back(x/i);
        }
    }
    facx.push_back(x);
    /*for(i = 0; i < facx.size(); i++){
        cout << facx[i] << endl;
    }*/
    bool endf = false;
    l = 0;
    for(i = k; i >= 1; i--){
        for(auto u : facx){
            if(u > i){
                continue;
            }
            if(i % u == 0){
                l = i;
                endf = true;
                break;
            }
        }
        if(endf) break;
    }
    cout << l << endl;
    
    return 0;
}
