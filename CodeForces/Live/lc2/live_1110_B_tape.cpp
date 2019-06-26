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

vector<lli> broken;
vector<lli> space;

int main(){
	IOS
	lli i;
	lli n, m, k;
	lli bi;
	
	cin >> n >> m >> k;
	for(i = 0; i < n; i++){
		cin >> bi;
		broken.push_back(bi);
	}
	
	if(k >= n){
		cout << n << endl;
		return 0;
	}
	
	for(i = 0; i < broken.size()-1; i++){
		space.push_back(broken[i+1] - broken[i] - 1);
	}
	sort(space.begin(), space.end());
	
	lli tape = n;
	for(i = 0; i < n-k; i++){
		tape += space[i];
	}
	
	cout << tape << endl;
	
	return 0;
}
