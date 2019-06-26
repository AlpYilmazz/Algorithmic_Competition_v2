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
#include <map>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

pair<double,bool> dp[101][51][35][26][4];
map<int,int> oc;
lli occur[5] = {0};


double solve(int c1, int c2, int c3, int c4, int last){
	if(dp[c1][c2][c3][c4][last].second){
		return dp[c1][c2][c3][c4][last].first;
	}
	
	int newc[5] = {0, c1, c2, c3, c4};
	newc[last-1]--;
	if(newc[1] == 0 && newc[1] == newc[2] && newc[2] == newc[3] && newc[3] == newc[4]){
		// permutation done - return value
		return last-1;
	}
	
	double total = 0.0;
	double expect = 0.0;
	
	total = (double)(newc[1] + 2*newc[2] + 3*newc[3] + 4*newc[4]);
	
	if(newc[1] > 0){
		double p1 = 1.0*newc[1] / total;
		expect += p1 * solve(c1-1, c2, c3, c4, 1);
	}
	if(newc[2] > 0){
		double p2 = 2.0*newc[2] / total;
		expect += p2 * solve(c1+1, c2-1, c3, c4, 2);
	}
	if(newc[3] > 0){
		double p3 = 3.0*newc[3] / total;
		expect += p3 * solve(c1, c2+1, c3-1, c4, 3);
	}
	if(newc[4] > 0){
		double p4 = 4.0*newc[4] / total;
		expect += p4 * solve(c1, c2, c3+1, c4-1, 4);
	}
		
	dp[c1][c2][c3][c4][last].second = true;
	return dp[c1][c2][c3][c4][last].first = expect;
}

/*
4
Kyiv 4
Lviv 7
Kharkiv 4
Donetsk 4
*/

int main(){
	IOS
	int i;
	int n;
	
	cin >> n;
	for(i = 0; i < n; i++){
		int sj;
		string city;
		cin >> city >> sj;
		oc[sj]++;
	}
	
	for(auto &it : oc){
		occur[it.second]++;
	}
	
	/*
	for(i = 1; i < 5; i++){
		cout << i << " times occur: " << occur[i] << endl;
	}
	*/
	
	cout << solve(occur[1], occur[2], occur[3], occur[4], 1) << endl;
	
	return 0;
}
