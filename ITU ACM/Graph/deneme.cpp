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

lli rec(lli a){
	if(a == 1) return a;
	return rec(a-1);
}

//p_ii moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
	IOS
	
	lli a = (lli)1e5;
	cout << rec(a) << endl;
	
	/*for(auto u : moves){
		cout << u.first << " " << u.second << endl;
	}*/
	
	return 0;
}
