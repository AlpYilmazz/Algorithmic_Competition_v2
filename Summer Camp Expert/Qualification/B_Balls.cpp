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

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

vector<lli> arr;
map<lli,lli> mp;

int main(){
	IOS
	lli i;
	lli n, ni;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> ni;
		arr.push_back(ni);
		if(mp.count(ni)){
			mp[ni]++;
		}
		else{
			mp.insert(pair<lli,lli>(ni, 1));
		}
		//cout << ni << ": " << mp[ni] << endl;
	}
	
	lli mx = -1;
	for(auto u : mp){
		mx = max(u.second, mx);
	}
	//cout << mx << endl;
	
	lli ans = 0;
	ans = ceil(((lli)arr.size() - mx) / (mx-1));
	
	cout << ans << endl;
	
	return 0;
}
