#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

unordered_set<lli> del_r;
unordered_set<lli> del_c;

int main(){
	IOS
	lli i; 
	lli n, m;
	lli row, col;
	lli total_del;
	
	cin >> n >> m;
	for(i = 0; i < m; i++){
		cin >> row >> col;
		del_r.insert(row);
		del_c.insert(col);
		
		total_del = del_r.size() * n;
		total_del += (n - del_r.size()) * del_c.size();
		cout << n*n - total_del << " ";
	}
	
	return 0;
}
