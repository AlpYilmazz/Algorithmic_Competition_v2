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

#define INF 1000000000007

vector<vector<int>> build;
lli time = INF;
int all_zero = 0;
int n, m;

void floor_pass(lli f, lli side, lli t){
	int i;
	lli last_open; 
	if(side == 0){ // left
		last_open = 0;
		for(i = 1; i <= m; i++){
			if(build[f][i] == 1){
				last_open = i;
			}
		}
		t += last_open;
	}
	else{ // right
		last_open = m+1;
		for(i = m; i >= 1; i--){
			if(build[f][i] == 1){
				last_open = i;
			}
		}
		t += (m+1-last_open);
	}
	if(f + all_zero < n-1){
		floor_pass(f+1, 0, t + last_open + 1);
		floor_pass(f+1, 1, t + (m+1-last_open) + 1);
	}
	else{
		time = min(time, t);
	}
}

int main(){
	IOS
	int i, j;
	
	cin >> n >> m;
	build.resize(n);
	for(i = n-1; i >= 0; i--){
		string s;
		cin >> s;
		for(j = 0; j < m+2; j++){
			build[i].push_back(s[j] - '0');
		}
	}
	
	bool stop = false;
	for(i = n-1; i >= 0; i--){
		for(j = 1; j <= m; j++){
			if(build[i][j] == 1){
				stop = true;
				break;
			}
		}
		if(stop){
			break;
		}
		all_zero++;
	}
	
	floor_pass(0, 0, 0);
	
	cout << time << endl;
	
	return 0;
}
