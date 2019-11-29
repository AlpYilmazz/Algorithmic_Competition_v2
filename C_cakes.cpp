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

vector<string> grid;
vector<vector<lli>> ans;
vector<lli> cnt;

int main(){
	IOS
	lli i, j;
	lli h, w, k;
	lli sub;

	cin >> h >> w >> k;
	grid.resize(h);
	ans.resize(h, vector<lli>(w, -1));
	cnt.resize(h, 0);
	for(i = 0; i < h; i++){
		cin >> grid[i];
	}

	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(grid[i][j] == '#'){
				cnt[i]++;
			}
		}
	}

	sub = 1;
	bool found = false;
	lli fir_line;
	for(i = 0; i < h; i++){
		if(!found && cnt[i] > 0){
			found = true;
			fir_line = i;
		}
		if(!found && cnt[i] == 0){
			continue;
		}

		bool fir_found = false;
		for(j = 0; j < w; j++){
			if(cnt[i] == 0){
				ans[i][j] = ans[i-1][j];
			}
			else{
				if(grid[i][j] == '#'){
					if(fir_found){
						sub++;
					}
					else{
						fir_found = true;
					}
				}
				ans[i][j] = sub;
			}
		}
		if(cnt[i] > 0){
			sub++;
		}
	}

	for(i = 0; i < fir_line; i++){
		for(j = 0; j < w; j++){
			ans[i][j] = ans[fir_line][j];
		}
	}

	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			cout << ans[i][j];
			if(j != w-1){
				cout << " ";
			}
		}
		cout << endl;
	}

	
	return 0;
}
