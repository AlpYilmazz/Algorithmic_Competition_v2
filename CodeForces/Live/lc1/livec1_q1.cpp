#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<int> flo;

int main(){
	IOS
	int i;
	int x;
	int n, ai;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> ai;
		flo.push_back(ai);
	}
	
	lli ans, best;
	for(x = 0; x < n; x++){
		ans = 0;
		for(i = 0; i < n; i++){
			ans += flo[i] * 2 * (abs(x-i) + i + x);
		}
		if(x == 0){
			best = ans;
		}
		else{
			best = min(best, ans);
		}
	}
	
	cout << best << endl;
	
	return 0;
}
