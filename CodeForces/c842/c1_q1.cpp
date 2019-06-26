#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int lli;

bool binary_search(lli xp_i, lli x, lli y, double k){
	lli b;
	lli pt = x;
	for(b = (y-x+1)/2; b >= 1; b /= 2){
		while(pt+b-1 <= y && ((double)xp_i / (double)pt+b-1) > k){
			pt += b-1;
		}
	}
	if(((double)xp_i / (double)pt) == k){
		return true;
	}
	return false;
}

int main(){
	lli i;
	lli r, l, x, y;
	double k;
	bool ans = false;
	
	scanf("%lld%lld%lld%lld%lf", &l, &r, &x, &y, &k);
	
	for(i = l; i <= r; i++){
		ans = binary_search(i, x, y, k);
		if(ans) break;
	}
	
	if(ans){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}

/*  ANSWER

// In the name of God

#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl;

int main() {
	IOS
	long long l,r,x,y,k;
	cin >> l >> r >> x >> y >> k;
	for(int i=x; i<=y; i++) {
		long long tmp = i*k;
		if(tmp<=r && tmp>=l) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
*/
