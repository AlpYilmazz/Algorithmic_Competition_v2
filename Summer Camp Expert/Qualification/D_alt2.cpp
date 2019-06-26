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

vector<lli> arr;
string moves;
lli total = 0;

int main(){
	IOS
	lli i;
	lli n, ni;

	cin >> n;
	for(i = 0; i < 2*n; i++){
		cin >> ni;
		arr.push_back(ni);
		total += ni;
	}
	
	lli head = 0, last = 2*n-1, mp = 0;
	for(i = 0; i < n; i++){
		lli case1, case2;
		double s1, s2;
		if(head+1 == last){
			case1 = arr[head] - arr[last];
			case2 = -case1;
			mp += max(case1, case2);
			if(case1 >= case2){
				moves.push_back('L');
			}
			else{
				moves.push_back('R');
			}
			break;
		}
		
		// case1 = m takes head
		if(arr[head+1] >= arr[last]){ // z takes head+1
			case1 = arr[head] - arr[head+1];
			s1 = case1 + (arr[head+2] + arr[last])/2.0;
		}
		else{ // z takes last
			case1 = arr[head] - arr[last];
			s1 = case1 + (arr[head+1] + arr[last-1])/2.0;
		}
		
		// case2 = m takes last
		if(arr[head] >= arr[last-1]){ // z takes head
			case2 = arr[last] - arr[head];
			s2 = case2 + (arr[head+1] + arr[last-1])/2.0;
		}
		else{ // z takes last-1
			case2 = arr[last] - arr[last-1];
			s2 = case2 + (arr[head] + arr[last-2])/2.0;
		}
		
		if(s1 > s2){
			moves.push_back('L');
			mp += case1;
			if(arr[head+1] >= arr[last]){
				head = head+2;
				last = last;
			}
			else{
				head = head+1;
				last = last-1;
			}
		}
		else{
			moves.push_back('R');
			mp += case2;
			if(arr[head] >= arr[last-1]){
				head = head+1;
				last = last-1;
			}
			else{
				head = head;
				last = last-2;
			}
		}
	}
	
	if(mp >= 0){
		cout << "Marichka" << endl;
		cout << moves << endl;
	}
	else{
		cout << "Zenyk" << endl;
	}
	
	return 0;
}
