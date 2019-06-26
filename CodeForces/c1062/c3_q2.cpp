#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	int i;
	
	for(i = 1; i <= 18; i++){
		cout << "72*" << i << ": " << sqrt(72 * i) << endl;;
	}
	
	return 0;
}
