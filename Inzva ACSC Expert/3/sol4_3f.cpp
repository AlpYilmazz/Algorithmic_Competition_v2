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

#define MAX (lli)1e9

vector<lli> arr;

bool is_true(int x){
	lli tot = 0;
	for(int i = 0; i < (int)arr.size(); i++){
		tot += arr[i] / (x+1);
	}
	return (tot <= 7);
}

int main(){
	IOS
	lli i;
	lli n, sj;

	cin >> n;
	for(i = 0; i < n; i++){
		cin >> sj;
		arr.push_back(sj);
	}

	lli l = 0, r = MAX;
	while(l < r){
		lli mid = (l+r) / 2;
		
		if(is_true(mid)) r = mid;
		else l = mid+1;
	}

	cout << l << endl;
	
	
	return 0;
}
