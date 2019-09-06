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

#define fi first
#define sc second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

vector<lli> arr[2];

lli solve(){
	lli i;
	lli n = (lli) arr[0].size();
	p_ii dp = make_pair(0, 0);
	
	for(i = 0; i < n; i++){
		p_ii next = make_pair(max(dp.fi, dp.sc + arr[0][i])
							, max(dp.sc, dp.fi + arr[1][i]));
		dp = next;
	}

	return max(dp.fi, dp.sc);
}

int main(){
	IOS
	lli i, row;
	lli n;
	
	cin >> n;
	for(row = 0; row < 2; row++){
		arr[row].resize(n);
		for(i = 0; i < n; i++){
			cin >> arr[row][i];
		}
	}

	cout << solve() << endl;

	return 0;
}
