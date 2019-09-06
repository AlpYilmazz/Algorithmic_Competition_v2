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

vector<lli> query;

int main(){
	IOS
	lli q;
	cin >> q;
	while(q--){
		lli i;
		lli n, m;
		lli sum;
		lli period, single_sum = 0;
		lli n_wave;
		set<lli> occur;

		cin >> n >> m;
		for(i = m; true; i += m){
			lli last_dig = i % 10;
			if(!occur.count(last_dig)){
				single_sum += last_dig;
				occur.insert(last_dig);
			}
			else{
				period = i - m;
				break;
			}
		}
		
		n_wave = n / period;
		sum = n_wave * single_sum;
		for(i = n_wave * period; i <= n; i += m){
			sum += i % 10;
		}
		query.push_back(sum);
	}

	for(auto qi : query){
		cout << qi << endl;
	}
	
	return 0;
}
