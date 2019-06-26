#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<lli> stave;

int main(){
	IOS
	lli i;
	lli n, k, l;
	lli ai;
	
	cin >> n >> k >> l;
	for(i = 0; i < n*k; i++){
		cin >> ai;
		stave.push_back(ai);
	}
	sort(stave.begin(), stave.end());
	
	lli lim = 0;
	for(lli b = stave.size()/2; b >= 1; b /= 2){
		while(lim+b < stave.size() && stave[lim+b] - stave[0] <= l){
			lim += b;
		}
	}
	
	if(lim+1 < n){
		cout << 0 << endl;
		return 0;
	}
	
	lli best = 0;
	lli free = lim+1 - n;
	for(i = 0; i <= lim; ){
		lli i_take = i;
		best += stave[i_take];
		if(free <= 0){
			i++;
			continue;
		}
		while(free > 0){
			i++;
			if(i >= i_take + k){
				break;
			}
			free--;
		}
		if(free <= 0){
			i++;
		}
	}
	cout << best << endl;
	
	return 0;
}
