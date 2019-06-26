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

vector<vector<int>> pref;
int avail[7];

bool found;
void state(int person, int n){
	if(person >= n){
		found = true;
	}
	if(found){
		return;
	}
	
	for(auto p : pref[person]){
		if(avail[p] == 0) continue;
		
		avail[p]--;
		state(person+1, n);
		avail[p]++;
	}	
}

int sizeVal(string &sz){
	if(sz == "XXS") return 0;
	else if(sz == "XS") return 1;
	else if(sz == "S") return 2;
	else if(sz == "M") return 3;
	else if(sz == "L") return 4;
	else if(sz == "XL") return 5;
	else if(sz == "XXL") return 6;
	return -1;
}

int main(){
	IOS
	int t;
	cin >> t;
	while(t--){
		pref.clear();
		int i;
		int n, m;
		cin >> n >> m;
		pref.resize(n);
		avail[0] = avail[1] = avail[2] = avail[3] = avail[4] = avail[5] = avail[6] = m/7;
		for(i = 0; i < n; i++){
			string s1, s2, s3;
			cin >> s1 >> s2 >> s3;
			pref[i].push_back(sizeVal(s1));
			pref[i].push_back(sizeVal(s2));
			pref[i].push_back(sizeVal(s3));
		}
		found = false;
		state(0, n);
		if(found){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
