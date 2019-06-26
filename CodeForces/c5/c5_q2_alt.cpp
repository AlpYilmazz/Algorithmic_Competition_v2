#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<lli> arr;

int main(){
	IOS
	lli i;
	lli n, m;
	lli ai, total = 0;
	lli ans;
	
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> ai;
		arr.push_back(ai);
		total += ai;
	}
	sort(arr.begin(), arr.end());
	
	lli need = 0, cover = 0;
	for(i = 0; i < n; i++){
		need++;
		if(arr[i] > cover){
			cover++;
		}
	}
	need += arr[n-1] - cover;
	ans = total - need;
	
	cout << ans << endl;
	
	return 0;
}
