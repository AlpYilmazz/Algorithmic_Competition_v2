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

string s[2];
lli ans[2] = {0};

int main(){
	IOS
	lli i, j;
	lli n;
	string st;

	cin >> n;
	cin >> st;
	
	s[0] = st; s[1] = st;
	//s[0][1] = st; s[1][1] = st;

	//reverse(s[0][1].begin.(), s[0][1].end());
	//reverse(s[1][1].begin.(), s[1][1].end());

	for(int cnt = 0; cnt < 2; cnt++){
		char ch = '0' + cnt;
		char ch2 = '1' - cnt;
		for(i = (lli)st.size()-1; i >= 0; i--){
			if(s[cnt][i] == ch2) continue;
			ans[cnt]++;
			lli go = 0;
			double change = 0;
			while(s[cnt][i] == ch){
				change++;
				if(s[cnt][i] == ch){
					s[cnt][i] = ch2;
				}
				i--;
				if(i < 0) break;
			}
			lli temp = change;
			if(i == -1){
				ans[cnt] += __builtin_popcount(change);
				break;
			}
			//debug(change);
			while(change > 1.0){
				change /= 2.0;
				go++;
			}
			//debug(go);
			go = pow(2, go);
			go -= temp;
			//debug(go);

			for(j = 0; j < go; j++){
				if(s[cnt][i-j] == ch){
					s[cnt][i-j] = ch2;
				}
				else{
					s[cnt][i-j] = ch;
				}
			}
		}
	}
	
	cout << ans[0] << endl;
	cout << min(ans[0], ans[1]) << endl;
	
	return 0;
}
