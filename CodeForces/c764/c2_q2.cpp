#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define debug(x) cout << #x ": " << x << endl

vector<lli> cubes;

int main(){
	int i;
	int n;
	lli ai;
	
	cin >> n;
	cubes.resize(n+1);
	for(i = 1; i <= n; i++){
		cin >> ai;
		cubes[i] = ai;
	}
	
	for(i = 1; i <= (n-i+1); i++){
		if(i%2 == 1){
			swap(cubes[i], cubes[n-i+1]);
		}
	}
	
	for(i = 1; i <= n; i++){
		cout << cubes[i];
		if(i != n){
			cout << " ";
		}
	}
	
	return 0;
}
