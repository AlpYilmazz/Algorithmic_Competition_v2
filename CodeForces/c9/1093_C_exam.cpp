#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<ulli> b;
vector<ulli> a;

int main(){
	IOS
	ulli i;
	ulli n;
	ulli bi;
	
	cin >> n;
	b.resize(n/2 + 1);
	a.resize(n+1);
	for(i = 1; i < b.size(); i++){
		cin >> bi;
		b[i] = bi;
	}
	
	ulli last_lim = b[1];
	a[1] = 0;
	a[n] = b[1];
	for(i = 2; i < b.size(); i++){
		ulli k = 0;
		for(ulli cut = (b[i]+1)/2; cut >= 1; cut /= 2){
			while(k+cut <= b[i] && k+cut <= last_lim && b[i] - (k+cut) >= a[i-1]){
				k += cut;
			}
		}
		last_lim = k;
		/*if(b[i] == 1){
			last_lim = 1;
		}
		else if(b[i] == 0){
			last_lim = 0;
		}*/
		a[i] = b[i] - last_lim;
		a[n-i+1] = last_lim;
	}
	
	for(i = 1; i < a.size(); i++){
		cout << a[i];
		if(i != a.size()-1){
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}
