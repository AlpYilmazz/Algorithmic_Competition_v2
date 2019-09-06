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

int main(){
	IOS
	int t;
	cin >> t;
	while(t--){
		int i;
		int bun, beef, chic;
		int h, c;
		lli total = 0;

		cin >> bun >> beef >> chic;
		cin >> h >> c;

		if(h > c){
			if(bun > 2 * beef){
				total += beef * h;
				bun -= 2 * beef;
			}
			else{
				total += (bun / 2) * h;
				bun = 0;
			}

			if(bun > 2 * chic){
				total += chic * c;
				bun -= 2 * chic;
			}
			else{
				total += (bun / 2) * c;
				bun = 0;
			}
		}
		else{
			if(bun > 2 * chic){
				total += chic * c;
				bun -= 2 * chic;
			}
			else{
				total += (bun / 2) * c;
				bun = 0;
			}

			if(bun > 2 * beef){
				total += beef * h;
				bun -= 2 * beef;
			}
			else{
				total += (bun / 2) * h;
				bun = 0;
			}
		}

		cout << total << endl;
	}
	
	return 0;
}
