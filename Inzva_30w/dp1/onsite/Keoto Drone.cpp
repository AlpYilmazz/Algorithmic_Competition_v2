#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e7

vector<vector<int>> site;
vector<vector<int>> dp;

int main(){
    int i, j;
    int min_so_far, ans;
    int cij;
    int n, m;
    cin >> n >> m;
    
    site.resize(n);
    for(j = 0; j < m; j++){
        for(i = 0; i < n; i++){
            cin >> cij;
            site[i].push_back(cij);
        }
    }
    
    dp.resize(n);
    for(i = 0; i < n; i++){
        dp[i].resize(m);
    }
    
    for(i = 0; i < n; i++){
        min_so_far = INF;
        for(j = 0; j < m; j++){
            if(i == 0){
                dp[i][j] = site[i][j];
            }
            else{
                min_so_far = min(min_so_far, dp[i-1][j]);
                dp[i][j] = min_so_far + site[i][j];
            }
        }
    }
    
    ans = INF;
    for(j = 0; j < m; j++){
        ans = min(ans, dp[n-1][j]);
    }
    cout << ans << endl;
    
    return 0;
}
