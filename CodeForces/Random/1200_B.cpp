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

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		lli i;
		lli n, m, k;
		vector<lli> col;
		
		cin >> n >> m >> k;
		col.resize(n);
		for(i = 0; i < n; i++){
			cin >> col[i];
		}

		for(i = 0; i < n-1; i++){
			if(col[i+1] <= k){
				m += col[i];
			}
			else if(col[i] >= col[i+1]){
				m += col[i] - col[i+1] + k;
			}
			else if((col[i+1] - k) - col[i] <= m){
				m -= (col[i+1] - k) - col[i];
			}
			else{
				break;
			}
		}

		if(i == n-1){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}	
	
	return 0;
}
