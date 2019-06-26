#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		vector<lli> arr;
		vector<lli> dp;
		vector<lli> top;
		lli i;
		lli n;
		
		cin >> n;
		arr.resize(n);
		for(i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		top.resize(arr.size());
		lli t = 0;
		for(i = arr.size()-1; i >= 0; i--){
			t += arr[i];
			top[i] = t;
		}
		
		dp.resize(arr.size());
		t = 0;
		for(i = 1; i <= 3; i++){
			t += arr[dp.size()-i];
			dp[dp.size()-i] = t;
		}
		for(i = dp.size()-4; i >= 0; i--){
			dp[i] = max(top[i+1]-dp[i+1]+arr[i],
						max(top[i+2]-dp[i+2]+arr[i]+arr[i+1],
						top[i+3]-dp[i+3]+arr[i]+arr[i+1]+arr[i+2]));
		}
		cout << dp[0] << endl;
	}
	
	return 0;
}
