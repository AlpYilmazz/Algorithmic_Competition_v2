#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<lli> dig;

int main(){
	IOS
	lli i;
	lli k, b;
	
	cin >> b >> k;
	dig.resize(k);
	for(i = k-1; i >= 0; i--){
		cin >> dig[i];
	}
	
	if(b % 2 == 0){
		if(dig[0] % 2 == 0){
			cout << "even" << endl;
		}
		else{
			cout << "odd" << endl;
		}
	}
	else{
		lli odd_count = 0;
		for(i = 0; i < dig.size(); i++){
			if(dig[i] % 2 == 1){
				odd_count++;
			}
		}
		if(odd_count % 2 == 0){
			cout << "even" << endl;
		}
		else{
			cout << "odd" << endl;
		}
	}
	
	return 0;
}
