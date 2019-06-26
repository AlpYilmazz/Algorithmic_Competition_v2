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

vector<p_ii> pt;
vector<lli> x;
vector<lli> y;

int main(){
	IOS
	lli i;
	lli xi, yi;
	
	for(i = 0; i < 10; i++){
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
		pt.push_back(make_pair(xi,yi));
	}

	sort(x.begin(), x.end());
	sort(x.begin(), x.end());
	// sort(x.begin(), x.end());

	return 0;
}
