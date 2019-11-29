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
	IOS
	lli i;
	lli m;
	lli cnt5 = 0, cnt2 = 0;
	lli lim;

	cin >> m;

	for(i = 5; cnt5 < m; i += 5){
		lli num = i;
		while(num % 5 == 0){
			num /= 5;
			cnt5++;
		}
	}

	lim = i-5;
	if(cnt5 != m){
		cout << 0 << endl;
		return 0;
	}
	else{
		cout << 5 << endl;
		for(i = lim; i < lim+5; i++){
			cout << i << " ";
		}
	}

	/*
	lim = i-5;

	for(i = 2; i <= lim; i += 2){
		lli num = i;
		while(num % 2 == 0){
			num /= 2;
			cnt2++;
		}
	}
	*/

	
	return 0;
}
