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
	//IOS
	lli i;
	lli ans1, ans2;

	cout << "?";
	for(i = 1; i <= 100; i++){
		cout << " " << i;
	}
	cout << endl;
	cout.flush();
	
	cin >> ans1;

	cout << "?";
	for(i = 1; i <= 100; i++){
		cout << " " << (i << 7);
	}
	cout << endl;
	cout.flush();

	cin >> ans2;

	lli mask = 2*2*2*2*2*2*2 - 1; // 2^7-1
	lli x1 = (ans1 ^ mask) & (ans1);
	lli x2 = (ans2 ^ (mask << 7)) & (ans2);
	
	lli x = x1 + x2;
	cout << "! " << x << endl;
	
	cout.flush();

	return 0;
}
