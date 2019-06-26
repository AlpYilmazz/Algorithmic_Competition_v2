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
	lli s, vi, least, max_litre = 0;
	
	cin >> n >> s;
	for(i = 0; i < n; i++){
		cin >> vi;
		keg.push_back(vi);
		max_litre += vi;
		if(i == 0){
			least = vi;
		}
		else{
			least = min(least, vi);
		}
	}
	if(max_litre < s){
		cout << -1 << endl;
		return 0;
	}
	
	lli total = 0;
	for(i = 0; i < n; i++){
		total += keg[i] - least;
	}
	
	while(total < s){
		least--;
		total += n;
	}
	
	cout << least << endl;
	
	return 0;
}
