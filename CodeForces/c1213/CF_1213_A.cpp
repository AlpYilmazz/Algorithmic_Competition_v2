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

int main(){
	IOS
	lli i;
	lli n, xi;
	lli cnt[2] = {0, 0};

	cin >> n;
	for(i = 0; i < n; i++){
		cin >> xi;
		cnt[abs(xi)%2]++;
	}

	cout << min(cnt[0], cnt[1]) << endl;
	
	return 0;
}
