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

vector<lli> bar;

int main(){
	IOS
	lli i;
	lli n;
	lli total = 0, left = 0;
	lli ans = -1;

	cin >> n;
	bar.resize(n);
	for(i = 0; i < n; i++){
		cin >> bar[i];
		total += bar[i];
	}

	for(i = 0; i < n; i++){
		left += bar[i];
		lli right = total - left;
		if(ans == -1){
			ans = abs(right - left);
		}
		else{
			ans = min(abs(right - left), ans);
		}
	}

	cout << ans << endl;
	
	return 0;
}
