#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define N 100001
#define mod 1000000007

vector<int> near;

int main(){
	IOS
	int i;
	int x;
	char s[N];
	
	scanf("%s", s);
	near.push_back(0);
	x = 0;
	int len = strlen(s);
	for(i = 0; i < len; i++){
		if(s[i] == 'a'){
			near[x]++;
		}
		if(s[i] == 'b' && near[x] != 0){
			x++;
			near.push_back(0);
		}
	}
	
	lli ans = 1;
	for(i = 0; i < near.size(); i++){
		ans *= ((near[i]+1)%mod); // there are k+1 options for every
		ans %= mod;               // group of 'a'
	}                             // +1 if for the empty case
	ans--;
	
	cout << ans << endl;
	
	return 0;
}
