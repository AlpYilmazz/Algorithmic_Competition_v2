#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <deque>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
#define INF 1000000000

set<char> letters;
string str;

int main(){
	IOS
	lli i;
	lli n;
	
	cin >> n;
	cin >> str;
	for(i = 0; i < n; i++){
		letters.insert(str[i]);
	}
	
	vector<lli> len(str.size(), 0);
	for(auto c : letters){
		lli last = -1;
		for(i = 0; i < str.length(); i++){
			if(str[i] == c){
				last = i;
			}
			if(last == -1){
				len[i] = INF;
			}
			else{
				len[i] = max(len[i], i-last+1);
			}
		}
	}
	
	lli ans = INF;
	for(auto u : len){
		ans = min(u, ans);
	}
	
	cout << ans << endl;
	
	return 0;
}
