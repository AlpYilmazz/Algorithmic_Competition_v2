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
	int n, A, B, C, T;
	int ti, total = 0;
	
	cin >> n >> A >> B >> C >> T;
	for(i = 0; i < n; i++){
		cin >> ti;
		total += ti;
	}
	
	if(B >= C){
		cout << n * A << endl;
		return 0;
	}
	else{
		cout << n*A + n*T*(C-B) - (C-B)*total << endl;
		return 0;
	}
	
	return 0;
}
