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

vector<lli> pre;
vector<lli> suf;

int main(){
	IOS
	lli i;
	lli n, k;
	string st;

	cin >> n >> k;
	cin >> st;

	pre.resize(n, 0);
	suf.resize(n, 0);

	pre[k-1] = 1;
	pre[k] = 1;
	for(i = k+1; i < (lli)st.size(); i++){
		pre[i] = 2 * pre[i-1] - pre[i-k-1];
	}

	
	return 0;
}
