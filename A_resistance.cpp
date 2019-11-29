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
	lli a, b;
	lli ans = 0;

	cin >> a >> b;

	while(a != 0 && b != 0){
		if(a >= b){
			ans += a/b;
			a = a % b;
		}
		else if(b > a){
			ans += b/a;
			b = b % a;
		}
	}

	cout << ans << endl;
	
	return 0;
}
