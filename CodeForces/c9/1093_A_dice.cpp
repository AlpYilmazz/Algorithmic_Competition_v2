#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define INF 1000000000000

lli coins[6] = {2, 3, 4, 5, 6, 7};
vector<bool> ready;
vector<lli> value;

lli solve(lli x){
	if(x < 0) return INF;
	if(x == 0) return 0;
	if(ready[x]) return value[x];
	lli best = INF;
	for(auto c : coins){
		best = min(best, solve(x-c)+1);
	}
	value[x] = best;
	ready[x] = true;
	return best;
}

int main(){
	IOS
	int t;
	
	cin >> t;
	ready.resize(101, false);
	value.resize(101);
	while(t--){
		int xi;
		
		cin >> xi;
		cout << solve(xi) << endl;
	}
	
	return 0;
}
