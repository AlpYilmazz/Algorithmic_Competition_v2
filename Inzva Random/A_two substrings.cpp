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
	lli i;
	string s;
	
	cin >> s;
	
	vector<lli> ab;
	vector<lli> ba;
	for(i = 0; i < (lli)s.length()-1; i++){
		if(s[i] == 'A' && s[i+1] == 'B'){
			//cout << "AB: " << i << endl;
			ab.push_back(i);
		}
		if(s[i] == 'B' && s[i+1] == 'A'){
			//cout << "BA: " << i << endl;
			ba.push_back(i);
		}
	}
	
	if((lli)ab.size() == 0 || (lli)ba.size() == 0){
		cout << "NO" << endl;
		return 0;
	}
	
	sort(ab.begin(), ab.end());
	sort(ba.begin(), ba.end());
	
	
	lli ab_b = ab[0], ab_e = ab[(lli)ab.size()-1];
	lli ba_b = ba[0], ba_e = ba[(lli)ba.size()-1];
	/*
	cout << ab_b << " - " << ab_e << endl;
	cout << ba_b << " - " << ba_e << endl;
	*/
	if(abs(ab_b - ba_e) >= 2 || abs(ab_e - ba_b) >= 2){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}
