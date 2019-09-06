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

#define INF 1000000000
#define N 2000001
#define MAXa 200001

vector<int> arr;
vector<int> cntArr[MAXa]; // cntArr[i] = the array of cnt_js
					      // of the nums which can get to the
					      // num i after cnt_j steps

int main(){
	IOS
	int i;
	int n, k;
	
	cin >> n >> k;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(i = 0; i < n; i++){
		int x = arr[i];
		int cnt = 0;
		while(x > 0){
			cntArr[x].push_back(cnt);
			x /= 2;
			cnt++;
		}
		cntArr[x].push_back(cnt); // !! x = 0 !!
	}
	
	int ans = INF;
	for(i = 0; i < MAXa; i++){
		if((int) cntArr[i].size() < k) continue;
		
		sort(cntArr[i].begin(), cntArr[i].end());
		int sub_ans = 0;
		for(int j = 0; j < k; j++){
			sub_ans += cntArr[i][j];
		}
		ans = min(ans, sub_ans);
	}

	cout << ans << endl;

	return 0;
}
