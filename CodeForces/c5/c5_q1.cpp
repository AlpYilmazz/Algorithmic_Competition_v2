#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	int i;
	lli ans = 0;
	lli n, s;
	
	cin >> n >> s;
	
	for(i = n; i >= 1; i--){
		while(s - i >= 0){
			s -= n;
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
