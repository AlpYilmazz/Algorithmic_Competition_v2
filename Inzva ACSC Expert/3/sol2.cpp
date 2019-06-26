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
#include <map>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

map<string, lli> mp;

int main(){
	IOS
	lli i;
	lli n;

	cin >> n;
	for(i = 0; i < n; i++){
		string s;
		lli w;

		cin >> s >> w;
		if(mp[s] == 0) mp[s] = 0;
		mp[s] = max(w, mp[s]);
	}

	lli sum = 0;
	for(auto &it : mp){
		sum += it.second;
	}

	cout << sum << endl;
	
	return 0;
}
