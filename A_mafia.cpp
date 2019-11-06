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

#define INF 1000000000000

vector<lli> arr;

int main(){
	IOS
	lli i;
	lli n;

	cin >> n;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());

	lli play, ans = 0;
	while(true){
		play = arr[1] - arr[0] + 1;
		for(i = 1; i < (int)arr.size(); i++){
			arr[i] -= play;
		}
		ans += play;

		for(lli j = 1; arr[j-1] > arr[j]; j++){
			lli temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
		}
		if(arr[0] == 0){
			break;
		}
	}
	ans += arr[arr.size()-1];

	cout << ans << endl;

	
	return 0;
}
