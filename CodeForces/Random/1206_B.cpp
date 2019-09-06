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

vector<lli> arr;

int main(){
	IOS
	lli i;
	lli n;
	lli cost = 0, minus = 0, zero = 0, plus = 0;
	
	cin >> n;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(i = 0; i < n; i++){
		if(arr[i] <= -1){
			cost += -arr[i] - 1;
			minus++;
		}
		if(arr[i] == 0){
			zero++;
		}
		if(arr[i] >= 1){
			cost += arr[i] - 1;
			plus++;
		}
	}

	if(minus % 2 == 1){
		if(zero != 0){
			cost++;
			zero--;
		}
		else{
			cost += 2;
		}
	}
	cost += zero;

	cout << cost << endl;

	
	return 0;
}


