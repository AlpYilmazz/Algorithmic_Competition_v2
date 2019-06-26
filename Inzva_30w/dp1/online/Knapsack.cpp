#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int k, vector<int> arr){
    int dp[k+1]; 
    memset(dp, 0, sizeof dp); 
    
    int ans = 0; 
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] <= i){
                dp[i] = max(dp[i], dp[i-arr[j]] + arr[j]);
            }
        }
    }
  
    return dp[k]; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int i;
        int ni;
        int n, k;
        vector<int> arr;
        
        cin >> n >> k;
        for(i = 0; i < n; i++){
            cin >> ni;
            arr.push_back(ni);
        }
        cout << unboundedKnapsack(k, arr) << endl;
    }
}
