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

int nth_digit(lli num, lli dig){
	return (num / )
}

lli avesome(lli x){ // # of avesome in [0,x]
	
}

int main(){
	IOS
	lli i;
	lli k, ans;
	
	cin >> k;
	
	lli l = 1, r = (lli)1e9;
	while(l < r){
		lli mid = (l+r)/2;
		ans = mid;
		lli ave = avesome(mid);
		if(ave < k) l = mid;
		else r = mid;
	}
	
	cout << ans << endl;
	
	return 0;
}
