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
		string s;
		vector<lli> next;
		
		cin >> s;
		next.resize(s.length());
		for(i = 0; i < (lli) s.length(); i++){
			if(s[i] == '1'){
				next[i] = i;
			}
			else{
				next[i] = (i == 0) ? -1 : next[i-1];
			}
		}
		
		lli ans = 0;
		for(lli r = 0; r < (lli) s.length(); r++){
			lli sum = 0;
			for(lli l = r; l >= 0 && r-l+1 < 20; l--){
				if(s[l] == '0') continue;

				sum += 1 << (r-l);
				if(sum <= r - ((l == 0 ? -1 : next[l-1]))){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
