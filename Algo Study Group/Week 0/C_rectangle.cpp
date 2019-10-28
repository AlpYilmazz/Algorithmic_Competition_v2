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

int main(){
	IOS
	double w, h;
	double x, y;

	cin >> w >> h >> x >> y;

	double area;
	lli mult = 0;
	if(x == w/2.0 && y == h/2.0){
		mult = 1;
	}
	area = (w*h) / 2.0;

	cout << area << " " << mult << endl;
	
	return 0;
}
