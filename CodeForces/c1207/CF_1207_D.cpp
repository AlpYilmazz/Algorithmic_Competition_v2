#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sc second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define mod 998244353

vector<vector<p_ii>> seq(2);
vector<lli> fac;

lli mult(lli x, lli y){
	return (x%mod * y%mod) % mod;
}

lli sum(lli x, lli y){
	return (x%mod + y%mod) % mod;
}

int main(){
	IOS
	lli i;
	lli n, ai, bi;
	lli ans;

	cin >> n;
	for(i = 0; i < n; i++){
		cin >> ai >> bi;
		seq[0].push_back(make_pair(ai, bi));
		seq[1].push_back(make_pair(bi, ai));
	}
	
	fac.resize(n+1);
	fac[0] = 1;
	for(i = 1; i < (lli) fac.size(); i++){
		fac[i] = mult(i, fac[i-1]);
	}

	ans = fac[n];
	for(int c = 0; c < 2; c++){
		sort(seq[c].begin(), seq[c].end());
		
		lli bad = 1;
		for(i = 0; i < n; ){
			lli j = i+1;
			while(j < n && seq[c][i].fi == seq[c][j].fi){
				j++;
			}
			bad = mult(bad, fac[j - i]);
			i = j;
		}
		ans = sum(ans, mod - bad);
	}
	
	lli bad = 1;
	for(i = 0; i < n; ){
		lli j = i+1;
		while(j < n && seq[0][i].fi == seq[0][j].fi){
			j++;
		}
		map<lli,lli> m;
		for(lli temp = i; temp < j; temp++){
			++m[seq[0][temp].sc];
		}
		for(auto cnt : m){
			bad = mult(bad, fac[cnt.sc]);
		}
		i = j;
	}
	
	for(i = 0; i < n-1; i++){
		if(seq[0][i].sc > seq[0][i+1].sc){
			bad = 0;
		}
	}

	ans = sum(ans, bad);

	cout << ans << endl;

	return 0;
}
