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

vector<lli> pref[2];

void calcPrefixArr(string &pattern, lli type){
	int len = 0;
	int i = 1;
	
	pref[type].resize(pattern.size());
	pref[type][0] = 0;
	
	while(i < pattern.size()){
		if(pattern[i] == pattern[len]){
			len++;
			pref[type][i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = pref[type][len-1];
			}
			else{
				pref[type][i] = 0;
				i++;
			}
		}
	}
}

bool kmp(string &text, string &pattern){
	pref[0].clear();
	calcPrefixArr(pattern, 0);
	lli i = 1, j = 0;
	lli pat_size = (lli) pattern.size();
	lli text_size = (lli) text.size();
	
	while(i < text_size-1){
		if(j == pat_size){
			return true;
		}
		
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{
			if(j != 0){
				j = pref[0][j-1];
			}
			else{
				i++;
			}
		}
	}
	
	return j == pat_size;
}

bool same(lli ind, string &s){
	lli i;
	lli size = (lli) s.size();
	for(i = 0; i < ind; i++){
		if(s[i] != s[size-ind+i]){
			return false;
		}
	}
	return true;
}

int main(){
	IOS
	lli i;
	lli s, size;
	lli found;
	
	cin >> s;
	size = (lli) s.size();
	calcPrefixArr(s, 1);
	for(i = pref[1][size-1]; i > 0; i--){
		string t;
		if(same(i, s)){
			for(lli j = 0; j < i; j++){
				t.push_back(s[i]);
			}
			if(kmp(s, t)){
				cout << t << endl;
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
	
	
	return 0;
}
