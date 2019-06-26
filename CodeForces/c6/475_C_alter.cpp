#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define mod 1000000009

vector<lli> s;

int main(){
	IOS
	lli i;
	string str;
	lli n, a, b, k;
	
	cin >> n >> a >> b >> k;
	cin >> str;
	s.resize(k);
	for(i = 0; i < k; i++){
		if(str[i] == '+'){
			s[i] = 1;
		}
		else{
			s[i] = -1;
		}
	}
	
	lli base = 0;
	for(i = 0; i < k; i++){
		base += s[i] * ((lli) pow(a, n-i)) * ((lli) pow(b, i));
		base %= mod;
	}
	if(base < 0){
		base += mod;
	}
	
	lli fac =  pow(b / a, k);
	
	
	
	return 0;
}
