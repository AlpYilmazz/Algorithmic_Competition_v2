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

vector<lli> seq;
vector<lli> occur;
vector<p_ii> oc_i;

int main(){
	IOS
	lli i;
	lli n, m, ai;
	
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> ai;
		seq.push_back(ai);
	}
	sort(seq.begin(), seq.end());
	
	
	return 0;
}
