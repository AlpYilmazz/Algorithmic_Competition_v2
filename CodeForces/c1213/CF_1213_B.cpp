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

#define INF 1000000007

vector<lli> testCase;

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		lli i;
		lli n, min_so_far = INF;
		lli bad = 0;
		vector<lli> day;
	
		cin >> n;
		day.resize(n);
		for(i = 0; i < n; i++){
			cin >> day[i];
		}

		for(i = n-1; i >= 0; i--){
			if(day[i] > min_so_far){
				bad++;
			}
			min_so_far = min(day[i], min_so_far);
		}
		testCase.push_back(bad);
		//cout << bad << endl;
	}

	for(auto ci : testCase){
		cout << ci << endl;
	}

	return 0;
}
