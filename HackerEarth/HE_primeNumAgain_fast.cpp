#include <vector>
#include <iostream>

using namespace std;

typedef long long int lli;

#define N 10001
#define INF 1000000007

vector<bool> sieve(N, true);
vector<int> prime;
vector<int> primatic;
vector<int> minCoinArr(N, INF);

lli fast_exp(lli n, lli k){ // = n^k
    if(k == 0) return 1;
    if(k == 1) return n;
    
    lli temp = fast_exp(n, k>>1);
    
    if((k&1) == 1) return temp * temp * n;
    return temp * temp;
}

void fill_sieve(){
    int last_pp = -1;
    sieve[0] = false; sieve[1] = false;
    
    for(int i = 2; i < N; i++){
        if(sieve[i]){ // i is prime
            prime.push_back(i);
            primatic.push_back(i);
            for(int j = i*i; j < N; j += i){
                sieve[j] = false;
            }
        }
        else{ // i might be prime^prime
            for(int j = last_pp+1; j < (int) prime.size(); j++){
                int p = prime[j];
                if(i < fast_exp(p, p)) break;
                if(i = fast_exp(p, p)){
                    last_pp = j;
                    primatic.push_back(i);
                    break;
                }
            }
        }
    }
}

int min_coin(int target){ // coins => primatic
    if(target == 0) return 0;
    if(minCoinArr[target] != INF) return minCoinArr[target];
    
    int ans = INF;
    
    for(auto prim : primatic){
        if(prim > target) break;
        
        int sub_ans = min_coin(target-prim);
        
        ans = min(sub_ans+1, ans);
    }
    minCoinArr[target] = ans;
    return ans;
}

void fill_minCoinArr(){
    for(int i = 0; i < N; i++){
        min_coin(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill_sieve();
    fill_minCoinArr();
    /*for(int i = (int)primatic.size()/2; i < (int)primatic.size(); i++){
        cout << primatic[i] << endl;
    }
    cout << "--------------------------" << endl;*/
    
    int t;
    cin >> t;
    while(t--){
        int n;
        
        cin >> n;
        cout << minCoinArr[n] << endl;
    }
    
    return 0;
}
