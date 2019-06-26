#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <utility>
#include <tuple>
#include <map>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;
/*
class lamp{
	friend bool compc_fg(char c1, char c2);
	public:
		char color;
		lli size;
		
		lamp(){};
		lamp(char c, lli s) : color(c), size(s) {};
		bool operator<(lamp &);
		bool operator>(lamp &);
};

bool compc_fg(char c1, char c2){
	if(c1 == c2) return false;
	if(c1 == 'R') return true;
	else if(c1 == 'G'){
		if(c2 == 'R') return false;
		return true;
	}
	else if(c1 == 'B'){
		if(c2 == 'R' || c2 == 'G') return false;
		return true;
	}
	else{ // if(c1 == 'Y')
		return false;
	}
}

bool lamp::operator<(lamp &other){
	if(size == other.size){
		return compc_fg(other.color, color);
	}
	return (size < other.size);
}

bool lamp::operator>(lamp &other){
	if(size == other.size){
		return compc_fg(color, other.color);
	}
	return (size > other.size);
}
*/

#define INF (lli)1000000005

map<char,lli> ch_order;
char colors[4];
vector<pair<lli,lli>> L;
vector<bool> used;
map<lli,lli> mp;
lli dp[101][51][35][26][4];
lli occ[5] = {0};

lli solve(int c1, int c2, int c3, int c4, int last){
	int C[5] = {0, c1, c2, c3, c4};
	lli ans = dp[c1][c2][c3][c4][last];

	if(ans != -1){
		return ans;
	}
	
	if((C[1] | C[2] | C[3] | C[4]) == 0){
		return dp[c1][c2][c3][c4][last] = 1;
	}
	
	ans = 0;
	for(int i = 1; i <= 4; i++){
		lli newc = C[i];
		lli cnt, res_i;

		if(last-1 == i){
			newc--;
		}
		if(newc == 0){
			continue;
		}

		cnt = i*newc;

		C[i]--;
		C[i-1]++;

		res_i = solve(C[1], C[2], C[3], C[4], i);
		ans = min(INF, ans + min(INF, cnt*res_i));

		C[i]++;
		C[i-1]--;
	}

	return dp[c1][c2][c3][c4][last] = ans;
}

/*
4 4
B4 R7 B7 Y2
*/

int main(){
	IOS
	lli i;
	lli n, k;
	string sl;
	
	cin >> n >> k;

	colors[0] = 'Y'; ch_order.insert(make_pair('Y', 0));
	colors[1] = 'B'; ch_order.insert(make_pair('B', 1));
	colors[2] = 'G'; ch_order.insert(make_pair('G', 2));
	colors[3] = 'R'; ch_order.insert(make_pair('R', 3));

	for(i = 0; i < n; i++){
		cin >> sl;
		lli num = 0, beta = 1;
		for(lli cnt = (lli)sl.size()-1; cnt >= 1; cnt--){
			num += (sl[cnt] - '0') * beta;
			beta *= 10;
		}
		L.push_back(make_pair(num, ch_order[sl[0]]));
	}
	sort(L.begin(), L.end()); // min -> max
	used.resize(n, false);
	memset(dp, -1, sizeof(dp));

	for(i = 0; i < L.size(); i++){
		mp[L[i].first] = 0;
	}
	for(i = 0; i < L.size(); i++){
		mp[L[i].first]++;
	}
	for(auto &it : mp){
		occ[it.second]++;
	}

	if(solve(occ[1], occ[2], occ[3], occ[4], 1) < k){
		cout << "NONE" << endl;
		return 0;
	}

	lli prev = -1;
	for(lli t = 0; t < n; t++){
		
		for(i = (lli)L.size()-1; i >= 0; i--){
	
			if(!used[i] && L[i].first != prev){
				
				occ[mp[L[i].first]]--;
				mp[L[i].first]--;
				occ[mp[L[i].first]]++;
	
				lli count = solve(occ[1], occ[2], occ[3], occ[4], mp[L[i].first]+1);
				if(count >= k){
					used[i] = true;
					prev = L[i].first;

					cout << colors[L[i].second] << L[i].first;
					break;
				}
				else{
					k -= count;
				}

				occ[mp[L[i].first]]--;
				mp[L[i].first]++;
				occ[mp[L[i].first]]++;
			}
		}
		if(t != n-1) cout << "-";
	}
	
	return 0;
}
