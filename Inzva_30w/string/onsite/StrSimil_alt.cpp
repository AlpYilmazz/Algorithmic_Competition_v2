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

lli same(lli suf_i, string &s){
	lli i;
	lli size = (lli) s.size();
	lli ind = size-1 - suf_i;
	for(i = 0; i < ind; i++){
		if(s[i] != s[size-ind+i]){
			return i+1;
		}
	}
	return ind;
}

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		lli i;
		string s;
		lli size, ans;
		
		cin >> s;
		
		ans = 0;
		size = (lli) s.size();
		for(i = 0; i < size; i++){
			ans += same(i, s);
		}
		
		cout << ans;
	}
	
	
	return 0;
}
