#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define N 100001
#define mod 1000000007

lli dp[2][N] = {{0}};
vector<lli> a;

int main(){
	IOS
	lli i, j;
	lli n;
	lli ai;
	
	cin >> n;
	a.push_back(0);
	for(i = 1; i <= n; i++){
		cin >> ai;
		a.push_back(ai);
	}
	
	lli ways, ans = 0;
	for(i = 1; i <= n; i++){
		ways = 0;
		for(j = 1; j <= n; j++){
			if(i == 1){
				dp[0][j] = 1;
				ans += (dp[0][j])%mod;
				ans %= mod;
			}
			else if(j >= i){ // i != 1 && j - i >= 0
				if(dp[i%2][j-1] % (i-1) == 0){
					ways += (dp[i%2][j-1])%mod; // dp[i-1][j-1]
					ways %= mod;
				}
				if(a[j] % i == 0){
					dp[(i+1)%2][j] = (ways)%mod; // dp[i][j-1]
					dp[(i+1)%2][j] %= mod;
					ans += (dp[(i+1)%2][j])%mod;
					ans %= mod;
				}
			}
		}
	}
	
	cout << (ans)%mod<< endl;
	
	return 0;
}
