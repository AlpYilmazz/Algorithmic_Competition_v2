#include <vector>
#include <iostream>

using namespace std;

#define mod 1000000007
#define X 10001
#define K 101

typedef long long int lli;

vector<vector<lli>> dp(K, vector<lli>(X, 0));

void fill_dp(){
    lli i, j;
    
    for(i = 1; i < K; i++){
        dp[i][0] = 1;
        lli sum = 1;
        for(j = 1; j < X; j++){
            dp[i][j] = (sum)%mod;
            dp[i][j] %= mod;
            sum += dp[i][j];
            sum %= mod;
            if(j-i >= 0){
                sum -= dp[i][j-i];
                if(sum < 0){
                    while(sum < 0){
                        sum += mod;
                    }
                }
            }
        }
    }
}

int main(){
    fill_dp();
    
    /*for(int xi = 0; xi < 20; xi++){
        cout << dp[5][xi] << endl;
    }
    cout << "--------------------" << endl;*/
    
    int t;
    cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;
        
        cout << dp[k][x] << endl;
    }
    
    return 0;
}
