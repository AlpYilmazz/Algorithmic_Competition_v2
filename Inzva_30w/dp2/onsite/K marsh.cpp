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

int bug = 1;

class DirNode{
	public:
		lli up;
		lli down;
		lli right;
		lli left;
	
		DirNode(){
			up = 0;
			down = 0;
			right = 0;
			left = 0;
		}
};

vector<vector<char>> land;
vector<vector<DirNode>> dir;

int main(){
	IOS
	lli i, j;
	lli row, col;
	char st;
	
	cin >> row >> col;
	land.resize(row);
	dir.resize(row);
	for(i = 0; i < row; i++){
		land[i].resize(col);
		dir[i].resize(col);
		for(j = 0; j < col; j++){
			cin >> st;
			land[i][j] = st;
		}
	}
	
	
	return 0;
}
