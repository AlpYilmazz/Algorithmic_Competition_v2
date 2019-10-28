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

#define INF 1000000000000

lli dp[101][101][27];
lli c[27][27] = {{0}};
string name;

int main(){
	IOS
	int i, ki, th, cn;
	int k, n;
	char x, y;
	lli bonus;

	cin >> name >> k;
	cin >> n;

	for(i = 0; i < n; i++){
		cin >> x >> y >> bonus;
		c[x-'a'][y-'a'] = bonus;
	}
	
	for(i = 0; i < 101; i++){
		for(ki = 0; ki < 101; ki++){
			for(th = 0; th < 27; th++){
				dp[i][ki][th] = -INF;
			}
		}
	}
	
	dp[0][0][name[0]-'a'] = 0;
	for(th = 0; th < 27; th++){
		if('a'+th != name[i]){
			dp[0][1][th] = 0;
		}
	}

	for(i = 1; i < name.size(); i++){
		for(ki = 0; ki <= k && ki <= i+1; ki++){
			for(th = 0; th < 26; th++){
				for(cn = 0; cn < 26; cn++){
					//cout << 1 << endl;
					if('a'+th == name[i]){
						if(ki <= (i-1)+1){
							dp[i][ki][th] = max(dp[i-1][ki][cn] + c[cn][th], dp[i][ki][th]);
						}
					}
					else if(ki != 0){
						dp[i][ki][th] = max(dp[i-1][ki-1][cn] + c[cn][th], dp[i][ki][th]);
					}
				}
			}
		}
	}
	
	lli ans = -INF;
	i = name.size()-1;
	for(ki = 0; ki <= k && ki <= i+1; ki++){
		for(th = 0; th < 26; th++){
			ans = max(ans, dp[i][ki][th]);
		}
	}

	cout << ans << endl;
	
	
	return 0;
}
