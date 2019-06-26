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

int bug = 1;

int main(){
	IOS
	lli t;
	cin >> t;
	while(t--){
		vector<lli> price;
		lli i, j;
		lli n;
		
		cin >> n;
		price.resize(n);
		for(i = 0; i < n; i++){
			cin >> price[i];
		}
		
		lli profit = 0;
		for(i = price.size()-1; i >= 0; ){
			lli loss = 0;
			lli share = 0;
			for(j = i-1; price[j] < price[i]; j--){
				if(j < 0) break;
				loss += price[j];
				share++;
			}
			profit += (share * price[i]) - loss;
			i = j;
		}
		cout << profit << endl;
	}
	
	return 0;
}
