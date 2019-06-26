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
	lli n;
	
	cin >> n;
	cout << (n/2) + 1 << endl;
	
	return 0;
}
