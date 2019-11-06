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
set<p_ii> ladder;

int main(){
	IOS
	lli i;
	lli n, m;

	cin >> n >> m;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}

	lli up[2] = {0, 0};
	lli down[2] = {0, 0};
	lli level[2] = {0, 0};
	for(i = 0; i < n-1; i++){
		if(arr[i] == arr[i+1] && l == 0){
			level[0] = i;
		}

		if(arr[i] < arr[i+1] && u == 0){
			up[]
		}
	}
	
	return 0;
}
