#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main(){
    int t;
    cin >> t;
    for(int t_i = 0; t_i < t; t_i++){
        int i, k;
        long long int sum = 0, pro = 1;
        int n, temp;
        
        /*vector<int> deck;
        deck.resize(n+1, 0);
        for(i = 0; i <= n; i++){
            cout << deck[i] << endl;
        }*/
        
        cin >> n;
        long long int *deck = new long long int[n+1];
        for(i = 0; i <= n; i++){
            deck[i] = 0;
        }
        for(i = 0; i < n; i++){
            cin >> temp;
            deck[temp]++;
        }
        
        for(i = 0; i < n; i++){
            sum = ((sum%mod) + (deck[i]%mod)) % mod;
            pro = ((pro%mod) * (sum%mod)) % mod;
            if(pro == 0) break;
            sum--;
        }
        cout << pro << endl;
        delete [] deck;
    }
    
    return 0;
}
