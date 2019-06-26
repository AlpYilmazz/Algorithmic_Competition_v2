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

lli p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
set<lli> s;

lli maxn_x(lli pw, lli A){
	lli i;
	for(i = 1; i <= A; i++){
		if(pow(i, pw) > A) break;
	}
	return i-1;
}

int main(){
	IOS
	lli i, j;
	lli a, b;
	lli ans;
	
	while(true){
	cin >> a >> b;
	ans = a*b;
	for(i = 0; i < 11; i++){
		ans -= maxn_x(p[i], a) * (b/p[i]);
	}
	
	for(i = 1; i <= a; i++){
		for(j = 1; j <= b; j++){
			lli pw = pow(i, j);
			s.insert(pw);
		}
	}

	lli sz = s.size();
	debug(sz);
	debug(ans);
	}
	//cout << ans << endl;
	
	
	return 0;
}
