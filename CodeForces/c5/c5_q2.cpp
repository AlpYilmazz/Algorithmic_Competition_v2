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
	lli ai;
	lli ans = 0;
	
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> ai;
		arr.push_back(ai);
	}
	sort(arr.begin(), arr.end());
	
	lli free = arr[n-1];
	for(i = n-1; i >= 0; i--){
		if(free == 0){
			ans += arr[i] - 1;
		}
		else if(i == 0){
			ans += arr[i] - free;
			break;
		}
		else{
			if(arr[i] != arr[i-1]){
				free -= arr[i] - arr[i-1];
				ans += arr[i-1];
			}
			else{
				free--;
				ans += arr[i-1] - 1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
