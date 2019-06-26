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

#define INF (lli)1e9+5

vector<lli> array;
vector<lli> ans;

void cons(lli bas, int f_s, int digit) {
	if(digit == 0) return;
	array.push_back(bas*10+f_s);
	cons(bas*10+f_s, 4, digit-1);
	cons(bas*10+f_s, 7, digit-1);
}

lli find10(lli base, lli num){
	lli res = 0;
	lli fac = 1;
	while(num != 0 && res >= 0){
		if(num%10 >= base) return -1;
		res += (num%10) * fac;
		if(res >= INF){
			return INF;
		}
		num /= 10;
		fac *= base;
	}
	if(res < 0) return INF;
	return res;
}

int main(){
	IOS
	lli i, j;
	lli n;

	cin >> n;

	if(n == 4 || n == 7){
		cout << "INFINITY" << endl;
		return 0;
	}

	cons(0, 4, 13);
	cons(0, 7, 13);

	for(auto num : array){
		lli l = 5, r = (lli)1e9;
		while(l < r){
			lli mid = (l+r) / 2;
			lli num10 = find10(mid, num);
				
			if(num10 < n) l = mid+1;
			else r = mid;
		}
		//cout << l << endl;
		if(find10(l, num) == n){
			ans.push_back(l);
		}

		/*for(int b = 5; b <= 7; b++){
			bool found = true;
			lli  num2 = num;
			lli res = 0;
			lli fac = 1;
			while(num2 != 0 && res >= 0){
				if(num2%10 >= b){
					found = false;
					break;
				}
				res += (num2%10) * fac;			
				num2 /= 10;
				fac *= b;
			}
			if(!found) continue;
			if(res == num){
				ans.push_back(b);
			}
		}*/
	}
	
	if(ans.size() == 0){
		cout << "NONE" << endl;
	}

	sort(ans.begin(), ans.end());
	for(auto base : ans){
		cout << base << " ";
	}
	

	return 0;
}
