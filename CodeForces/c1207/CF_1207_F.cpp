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

#define N 500001
#define K 740

vector<lli> arr(N, 0);
vector<vector<lli>> sum(K, vector<lli>(K, 0));

int main(){
	IOS
	lli q;
	cin >> q;
	while(q--){
		lli i;
		lli t, x, y;

		cin >> t >> x >> y;
		if(t == 1){
			arr[x] += y;

			for(i = 1; i < K; i++){
				sum[i][x % i] += y;
			}
		}
		else{
			if(x >= K){
				lli ans = 0;
				for(i = y; i < N; i += x){
					ans += arr[i];
				}
				cout << ans << endl;
			}
			else{
				cout << sum[x][y] << endl;
			}
		}
	}
	
	return 0;
}
