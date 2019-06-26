#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	lli q;
	cin >> q;
	while(q--){
		lli k, a;
		cin >> a;
		
		for(k = 1; k <= a; k *= 2){
		}
		k--;
		if(a == k){
			cout << 1 << endl;
		}
		else{
			cout << k << endl;
		}
	}
	
	return 0;
}
