#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define mod 1000000007

vector<lli> arr;

int main(){
	IOS
	lli i;
	lli n, q;
	lli del;
	
	cin >> n >> q;
	cin >> del;
	arr.resize(n);
	i = n-1;
	while(i >= 0){
		arr[i] = del%10;
		del /= 10;
		i--;
	}
	
	while(q--){
		lli sum = 0;
		lli l, r;
		
		cin >> l >> r;
		l--; r--;
		vector<lli> temp;
		temp = arr;
		sort(temp.begin()+l, temp.begin()+r);
		
		for(i = r; i >= l; i--){
			sum += (temp[i]%mod) + (sum%mod);
			sum %= mod;
		}
		cout << sum << endl;
	}
	
	return 0;
}
