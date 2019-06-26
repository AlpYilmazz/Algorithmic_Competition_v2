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
	lli yelcr, blucr;
	lli yel, gre, blu;
	
	cin >> yelcr >> blucr;
	cin >> yel >> gre >> blu;
	
	lli need_y = (yel*2 + gre)-yelcr;
	lli need_b = (gre + blu*3)-blucr;
	
	if(need_y < 0) need_y = 0;
	if(need_b < 0) need_b = 0;
	
	cout << need_y + need_b << endl;
	
	return 0;
}
