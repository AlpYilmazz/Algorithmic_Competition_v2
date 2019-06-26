#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

lli kayra = 0, asya = 0;

int main(){
	IOS
	lli n;
	cin >> n;
	while(n--){
		lli i;
		lli b, m;
		char fir;
		cin >> b >> m >> fir;
		
		if(b%(m+1) == 1){ // start loses
			if(fir == 'K'){
				asya++;
			}
			else if(fir == 'A'){
				kayra++;
			}
		}
		else{ // start wins
			if(fir == 'K'){
				kayra++;
			}
			else if(fir == 'A'){
				asya++;
			}
		}
	}
	
	if(asya < kayra){
		// asya goes to ekmek
		cout << "Asya " << asya << endl;
	}
	else{
		// kayra goes to ekmek
		cout << "Kayra " << kayra << endl;
	}
	
	return 0;
}
