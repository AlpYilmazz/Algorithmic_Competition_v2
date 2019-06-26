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
lli freq[4][401] = {{0}};
lli size[4] = {0};

void solve(){
	
}

int main(){
	IOS
	lli i, j, m;
	lli n, c, k;
	lli cut;
	
	cin >> n >> c >> k;
	
	if(n < 4*k){
		cout << 0 << endl
		return 0;
	}
	
	arr.resize(n);
	for(i = 0, cut = 0; i < n; i++){
		cin >> arr[i];
		if(i == k || i == 2*k || i == 3*k){
			cut++;
		}
		freq[cut][arr[i]]++;
		size[cut]++;
	}
	
	lli 
	for(i = 0; i)
	
	
	return 0;
}
