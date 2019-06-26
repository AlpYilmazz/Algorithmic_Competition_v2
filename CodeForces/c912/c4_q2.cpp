#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	lli n, k;
	
	cin >> n >> k;
	
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	
	lli res = 1;
	while(res <= n){
		res <<= 1;
	}
	
	//lli c = log2(n)+1;
	//lli ans = (1 << c) - 1;
	cout << res-1 << endl;
	
	return 0;
}
