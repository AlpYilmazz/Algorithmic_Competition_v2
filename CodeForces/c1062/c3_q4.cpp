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
	int i;
	int n;
	
	cin >> n;
	
	lli total = 0;
	for(i = (n/2); i >= 2; i--){
		total += ( ((i) * (i + 1))/2 - 1 ) * 4;
	}
	
	cout << total << endl;
	
	return 0;
}
