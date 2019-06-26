#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define N 2001
#define M 2001

bool mat[N][M];

int main(){
	IOS
	int i, j;
	int n, m;
	int aij;
	
	cin >> n >> m;
	for(i = 0; i < n; i++){
		string s;
		cin >> s;
		for(j = 0; j < m; j++){
			if(s[j] == '1'){
				mat[i][j] = true;
			}
			else{
				mat[i][j] = false;
			}
		}
	}

	set<int> req;
	int index;
	for(j = 0; j < m; j++){
		int temp = 0;
		for(i = 0; i < n; i++){
			if(mat[i][j]){
				temp++;
				index = i;
			}
		}
		if(temp == 1){
			req.insert(index);
		}
	}
	if(req.size() == n){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
	
	return 0;
}
