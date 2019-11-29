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
	lli x, y;
	lli ans = 0;

	cin >> x >> y;

	if(x <= 3){
		ans += (4-x) * 100000;
	}
	if(y <= 3){
		ans += (4-y) * 100000;
	}

	if(x == 1 && y == 1){
		ans += 4 * 100000;
	}

	cout << ans << endl;
	
	return 0;
}
