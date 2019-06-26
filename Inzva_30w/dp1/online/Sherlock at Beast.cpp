#include <bits/stdc++.h>

using namespace std;

#define N 100001

vector<int> decent(N, -1);

int decent_num(int dig){
    int n = dig;
    while(n % 3 != 0 && n >= 0){
        if(decent[n] != -1) return decent[n];
        n -= 5;
    }
    if(n < 0){
        return -1;
    }
    decent[dig] = n;
    return decent[dig];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int i;
        int ans;
        int n;
        cin >> n;
        ans = decent_num(n);
        if(ans == -1){
            cout << -1 << endl;
        }
        else{
            for(i = 0; i < ans; i++){
                cout << 5;
            }
            for(; i < n; i++){
                cout << 3;
            }
            cout << endl;
        }
    }
    
    return 0;
}
