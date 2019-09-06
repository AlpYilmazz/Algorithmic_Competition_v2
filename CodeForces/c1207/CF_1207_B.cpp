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

#define fi first
#define sc second

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

#define N 51
#define M 51

vector<pair<int,int>> allp = {{0, 0}, {0, -1},
								{-1, 0}, {-1, -1}};
vector<vector<int>> A(N, vector<int>(M, 0));
vector<vector<int>> B(N, vector<int>(M, 0));
vector<pair<int,int>> operations;
int n, m;

bool can_choose(int x, int y){
	if(x >= n || x <= 0 || y >= m || y <= 0){
		return false;
	}
	int temp;
	temp = A[x][y] + A[x][y+1] + A[x+1][y] + A[x+1][y+1];
	if(temp == 4){
		return true;
	}
	return false;
}

void make_operation(int x, int y){
	B[x][y] = B[x][y+1] = B[x+1][y] = B[x+1][y+1] = 1;
	operations.push_back(make_pair(x, y));
}

int main(){
	IOS
	int i, j;
	
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			cin >> A[i][j];
		}
	}
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(A[i][j] != B[i][j]){
				int cnt = 0;
				for(auto pi : allp){
					cnt++;
					if(can_choose(i + pi.fi, j + pi.sc)){
						make_operation(i + pi.fi, j + pi.sc);
						break;
					}
					else if(cnt == 4){
						cout << -1 << endl;
						return 0
					}
				}
			}
		}
	}

	cout << operations.size() << endl;
	for(auto op : operations){
		cout << op.fi << " " << op.sc << endl;
	}

	return 0;
}
