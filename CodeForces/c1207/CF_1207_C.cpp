#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define INF 10000000000000007

vector<lli> ans;

int main(){
	IOS
	int t;
	cin >> t;
	while(t--){
		vector<vector<lli>> dp;
		string road;
		lli i;
		lli n, a, b;

		cin >> n >> a >> b;
		dp.resize(n, vector<lli>(2, INF));
		cin >> road;
	
		if(road[1] == '0'){
			dp[0][0] = a + b;
		}
		dp[0][1] = 2*a + b;
		for(i = 1; i < n-1; i++){
			lli i0 = min(dp[i-1][0] + a + b
						, dp[i-1][1] + 2*a + 2*b);
			lli i1 = min(dp[i-1][0] + 2*a + b
						, dp[i-1][1] + a + 2*b);
			if(road[i] == '0' && road[i+1] == '0'){
				dp[i][0] = i0;
				dp[i][1] = i1;
			}
			else{
				dp[i][1] = i1;
			}
		}
		dp[n-1][0] = min(dp[n-2][0] + a + 2*b
						, dp[n-2][1] + 2*a + 3*b);

		ans.push_back(dp[n-1][0]);
	}

	// cout << "---------------------" << endl;
	for(auto ai : ans){
		cout << ai << endl;
	}
	
	return 0;
}
