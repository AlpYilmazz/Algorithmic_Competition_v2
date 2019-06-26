#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007

typedef struct FibMx{
    long long a;
    long long b;
    long long c;
    long long d;
    
    void mod_all();
}FM;

void FibMx::mod_all(){
    a %= mod;
    b %= mod;
    c %= mod;
    d %= mod;
}

FM fm_mult(FM x, FM y){
    FM t;
    t.a = x.a*y.a + x.b*y.c;
    t.b = x.a*y.b + x.b*y.d;
    t.c = x.c*y.a + x.d*y.c;
    t.d = x.c*y.b + x.d*y.d;
    return t;
}

FM fm_pow(FM x, long long k){
    if(k == 1){
        x.mod_all();
        return x;
    }
    
    FM t = fm_pow(x, k>>1);
    FM ret;
    
    if((k&1) == 1){
        ret = fm_mult(x, fm_mult(t, t));
    }
    else{
        ret = fm_mult(t, t);
    }
    ret.mod_all();
    return ret;
}

long long Fib(long long n){
    FM fm = {1, 1, 1, 0};
    
    fm = fm_pow(fm, n-2);
    return (fm.a + fm.b) % mod;
}

bool is_prime(long long p){
    for(int i = 2; i <= sqrt(p); i++){
        if(p % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //cout << Fib(n) << endl;
        if(is_prime(Fib(n))){
            cout << "Prime" << endl;
        }
        else{
            cout << "Not Prime" << endl;
        }
    }
    
    return 0;
}

/*
long long fast_exp(long long x, long long k){
    if(k == 0) return 1;
    if(k == 1) return x;
    
    long long t = fast_exp(x, k>>1);
    
    if((k&1) == 1) return (x * t * t) % mod;
    return (t * t) % mod;
}
*/
