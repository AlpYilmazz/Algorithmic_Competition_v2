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

class frac{
	public:
		int nom;
		int denom;
};

pair<int,int> girl[10];
vector<frac> pj;
vector<frac> qj;
vector<frac> pb;
vector<frac> qb;



int main(){
	IOS
	int i;
	int n;
	pair<int,int> john, brus;
	
	cin >> n;
	cin >> john.first >> john.second;
	cin >> brus.first >> brus.second;
	for(i = 0; i < n; i++){
		cin >> girl[i].first >> girl[i].second;
	}
	
	
	
	
	
	return 0;
}
