#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <set>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int road[5][4] = {  {0, 0, 0, 0},
					{0, 4, 3, 2},
					{0, 1, 4, 3},
					{0, 2, 1, 4},
					{0, 3, 2, 1}  };

int lights[5][4];
set<int> cross;
set<int> ped;

int main(){
	IOS
	int i, j;
	int light;
	
	for(i = 1; i <= 4; i++){
		for(j = 1; j <= 4; j++){
			cin >> light;
			if(light == 1){
				if(j == 4){
					ped.insert(i); 
				}
				else{
					cross.insert(road[i][j]);
					cross.insert(i);
				}
			}
		}
	}
	for(auto u : cross){
		if(ped.count(u)){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}
