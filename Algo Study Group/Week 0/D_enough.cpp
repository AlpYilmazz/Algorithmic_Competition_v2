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

vector<lli> arr;

int main(){
	IOS
	lli i;
	lli n, k;
	
	cin >> n >> k;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	lli l = 0, r = -1;
	lli total = 0;
	while(total < k){
		r++;
		total += arr[r];
	}

	lli ans = 0;
	while(r < n && l <= r){
		if(total >= k){
			ans += n-r;
			total -= arr[l];
			l++;
			if(l > r){
				r++;
				if(r >= n) break;
				total += arr[r];
			}
		}
		else{
			r++;
			if(r >= n) break;
			total += arr[r];
		}
	}

	cout << ans << endl;

	return 0;
}
