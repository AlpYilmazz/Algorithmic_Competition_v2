#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

#define debug(x) cout << #x ": " << x << endl

int GCD(int n, int m){
	int temp = 0;
	
	while(n != 0){
		temp = n;
		n = m%n;
		m = temp;
	}
	return m;
}

int main(){
	int n, m, z;
	
	cin >> n >> m >> z;
	
	cout << z / (n*m / GCD(n, m)) << endl;
	
	return 0;
}
