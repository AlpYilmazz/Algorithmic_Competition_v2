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
	lli t;
	cin >> t;
	while(t--){
		lli str, intt, exp;
		lli exp_p;
		lli ans;

		cin >> str >> intt >> exp;

		if(str > intt){
			exp_p = exp - (str-intt);
			ans = (str-intt) + exp_p/2 + 1;
			if(exp_p <= 0) ans = exp + 1;
		}
		else{
			exp_p = exp - (intt-str);
			ans = exp_p/2 + 1;
			if(exp_p <= 0) ans = 0;
		}
		if(ans != 0 && exp_p % 2 == 0){
			ans--;
		}
		/*if(exp == 0){
			ans = (str > intt);
		}*/

		cout << ans << endl;
	}
	
	return 0;
}
