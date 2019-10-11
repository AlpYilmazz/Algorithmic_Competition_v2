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

#define INF 1000000000000000000

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		lli i;
		lli n, head;
		lli di, hi;
		lli max_blow = 0, max_net = -INF;

		cin >> n >> head;
		for(i = 0; i < n; i++){
			cin >> di >> hi;
			max_blow = max(max_blow, di);
			max_net = max(max_net, di - hi);
		}
		
		/*
		auto ascent = [](p_ii &b, p_ii &k){
			if(b.first == k.first){
				return b.second > k.second;
			}
			return b.first > k.first;
		};
		sort(net_blow.begin(), net_blow.end(), ascent);
		*/

		if(head - max_blow > 0 && max_net <= 0){
			cout << -1 << endl;
			continue;
		}
		if(head - max_blow <= 0){
			cout << 1 << endl;
			continue;
		}

		lli cnt = (head - max_blow) / max_net + 1;
		if((head - max_blow) % max_net != 0){
			cnt++;
		}

		cout << cnt << endl;
	}
	
	return 0;
}
