#include <bits/stdc++.h>

using namespace std;

#define N 200001
#define mod 1000000007

typedef long long int lli;

int substrings(char str[]){
    lli i;
    lli n = strlen(str);
    lli factor = 1, result = 0;
    vector<int> num;
    for(i = 0; i < n; i++){
        num.push_back(str[i] - '0');
    }
    
    for(i = n-1; i >= 0; i--){
        result += ( ((i+1)%mod) * (num[i]%mod) * (factor%mod) ) % mod;
        factor = ( (factor * 10)%mod + 1 ) %mod;
    }
    
    return (result%mod);
}

int main(){
    char str[N];
    
    scanf("%s", str);
    cout << substrings(str) << endl;
    
    return 0;
}
