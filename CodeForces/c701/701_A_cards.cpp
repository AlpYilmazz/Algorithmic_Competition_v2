#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<p_ii> cards;

int main(){
	IOS
	lli i;
	lli n;
	lli c;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> c;
		cards.push_back(make_pair(c, i));
	}
	sort(cards.begin(), cards.end());
	
	for(i = 0; i < n/2; i++){
		cout << cards[i].second+1 << " " << cards[n-1-i].second+1 << endl;
	}
	
	return 0;
}
