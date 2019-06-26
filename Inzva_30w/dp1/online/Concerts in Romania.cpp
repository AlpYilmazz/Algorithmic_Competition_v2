#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007

typedef long long int lli;

vector<lli> h;
vector<char> band;
vector<char> concert;
vector<lli> row_sum[2];
vector<vector<lli>> S;

lli scheduler(){
    lli sum = 0;
    lli i, j, a;
    
    for(i = 0; i < band.size(); i++){
        sum = 0;
        for(j = 0; j < concert.size(); j++){
            if(i == 0){
                if(concert[j] == band[0]){
                    S[i][j] = 1;
                    sum += 1;
                }
                row_sum[1][j] = (sum%mod);
            }
            else{
                if(concert[j] == band[i]){
                    S[i][j] = 0;
                    /*for(a = 0; a < j; a++){
                        if(a + h[band[i-1] - 'A'] >= j){
                            break;
                        }
                        if(concert[a] == band[i-1]){
                            S[i][j] += (S[i-1][a]%mod);           i tek -> tek kullan & çifte yaz
                        }                                        i çift -> çift kullan & teke yaz
                    }*/
                    if(j - h[band[i-1] - 'A'] - 1 >= 0){
                        S[i][j] += (row_sum[i%2][j - h[band[i-1] - 'A'] - 1]%mod);
                    }
                    sum += (S[i][j]%mod);
                }
                row_sum[(i+1)%2][j] = (sum%mod);
            }
        }
    }
    
    lli result = 0;
    for(j = 0; j < concert.size(); j++){
        if(concert[j] == band[band.size()-1]){
            result += (S[band.size()-1][j]%mod);
            result %= mod;
        }
    }
    return result;
}

int main(){
    int i;
    int k, n;
    
    cin >> k >> n;
    for(i = 0; i < 26; i++){
        lli hi;
        cin >> hi;
        h.push_back(hi);
    }
    for(i = 0; i < k; i++){
        char ki;
        cin >> ki;
        band.push_back(ki);
    }
    for(i = 0; i < n; i++){
        char ni;
        cin >> ni;
        concert.push_back(ni);
    }
    
    S.resize(band.size());
    for(i = 0; i < band.size(); i++){
        S[i].resize(concert.size());
    }
    row_sum[0].resize(concert.size());
    row_sum[1].resize(concert.size());
    
    cout << scheduler() << endl;
    
    return 0;
}
