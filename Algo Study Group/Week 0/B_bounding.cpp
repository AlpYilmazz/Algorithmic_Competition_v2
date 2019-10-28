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
vector<lli> pre;

int main(){
	IOS
	lli i;
	lli n, x;
	
	cin >> n >> x;
	arr.resize(n);
	pre.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}

	pre[0] = arr[0];
	for(i = 1; i < n; i++){
		pre[i] = pre[i-1] + arr[i];
	}

	i = 0;
	lli di = 0, jump = 0;
	/*while(di <= x && i < n){
		jump++;
		di = di + arr[i];
		i++;
	}*/

	for(i = 0; i < n; i++){
		if(pre[i] > x){
			break;
		}
	}
	i--;
	
	jump = i+2;
	cout << jump << endl;

	return 0;
}
