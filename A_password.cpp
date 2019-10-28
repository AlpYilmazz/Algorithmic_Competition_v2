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

vector<vector<int>> dp;
string form;
vector<char> s;
int n;

int main(){
	IOS
	lli i, c;

	cin >> n;
	cin >> form;
	s.resize(form.size()+1);
	dp.resize(form.size()+1, vector<int>(n, -1));

	for(c = 0; c <= n-1; c++){
		dp[0][c] = -2;
	}

	for(i = 1; i < dp.size(); i++){
		for(c = 0; c <= n-1; c++){
			if(form[i-1] == '='){
				if(dp[i-1][c] != -1){
					dp[i][c] = c;
				}
			}
			else if(form[i-1] == '<'){
				for(int chi = 0; chi <= c-1; chi++){
					if(dp[i-1][chi] != -1){
						dp[i][c] = chi;
					}
				}
			}
			else{ // if(form[i-1] == '>')
				for(int chi = c+1; chi <= n-1; chi++){
					if(dp[i-1][chi] != -1){
						dp[i][c] = chi;
					}
				}
			}
		}
	}

	for(c = 0; c <= n-1; c++){
		if(dp[dp.size()-1][c] != -1){
			s[dp.size()-1] = 'a' + c;
			char c_next = c;
			for(i = dp.size()-1; i >= 1; i--){
				s[i-1] = 'a' + dp[i][c_next];
				c_next = dp[i][c_next];
			}

			break;
		}
	}
	if(c == n){
		cout << -1 << endl;
		return 0;
	}

	for(auto ci : s){
		cout << ci;
	}
	cout << endl;
	

	return 0;
}
