#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	lli i;
	lli l, r, x, y, k;
	
	cin >> l >> r >> x >> y >> k;
	for(i = x; i <= y; i++){
		lli bar = i*k;
		if(l <= bar && bar <= r){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}
