#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int main(){
	IOS
	int t;
	cin >> t;
	while(t--){
		int i, j;
		vector<int> occur(26, 0);
		string s;
		cin >> s;
		for(i = 0; i < s.length(); i++){
			occur[s[i] - 'a']++;
		}
		bool flag = false;
		for(i = 0; i < occur.size(); i++){
			if(occur[i] != 0){
				if(occur[i] == s.length()){
					cout << -1 << endl;
					flag = true;
					break;
				}
			}
		}
		if(flag) continue;
		
		for(i = 0; i < occur.size(); i++){
			for(j = 0; j < occur[i]; j++){
				cout << (char)('a' + i);
			}
		}
		cout << endl;
	}
	
	return 0;
}
