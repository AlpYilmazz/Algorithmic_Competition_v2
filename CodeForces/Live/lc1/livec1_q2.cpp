#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<int> keg;

int main(){
	IOS
	int i;
	int n;
	lli s, vi, max_litre = 0;
	
	cin >> n >> s;
	for(i = 0; i < n; i++){
		cin >> vi;
		keg.push_back(vi);
		max_litre += vi;
	}
	if(max_litre < s){
		cout << -1 << endl;
		return 0;
	}
	
	sort(keg.begin(), keg.end());
	
	lli total = 0;
	for(i = n-1; i >= 0; i--){
		if(i != 0){
			total += keg[i] - keg[0];
			keg[i] -= keg[i] - keg[0];
		}
		
		if(total >= s){
			break;
		}
		
		if(i == 0){
			total += 1;
			keg[0] -= 1;
			if(total != s){
				i = n-1;
			}
		}
	}
	
	cout << keg[0] << endl;
	
	return 0;
}
