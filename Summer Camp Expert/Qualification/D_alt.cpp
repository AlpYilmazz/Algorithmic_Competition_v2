#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<int,int> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

map<p_ii, lli> dp;
map<p_ii, lli> moves;
vector<lli> arr;
lli point[2] = {0, 0};
//vector<char> moves;
bool m_wins = false;
lli total = 0;

lli cnt = 0;
lli solve(int head, int last){
	cnt++;
	lli case1, case2;
	if(head+1 == last){
		case1 = arr[head] - arr[last];
		case2 = arr[last] - arr[head];
		dp.insert({{head,last}, 0});
		return (dp[{head, last}] = max(case1, case2));
	}
	
	// case1 = m takes head
	if(arr[head+1] >= arr[last]){ // z takes head+1
		if(dp.count({head+2, last})){
			case1 = dp[{head+2, last}] + arr[head] - arr[head+1];
		}
		else{
			case1 = solve(head+2, last);
		}
	}
	else{ // z takes last
		if(dp.count({head+1, last-1})){
			case1 = dp[{head+1, last-1}] + arr[head] - arr[last];
		}
		else{
			case1 = solve(head+1, last-1);
		}
	}
	
	// case2 = m takes last
	if(arr[head] >= arr[last-1]){ // z takes head
		if(dp.count({head+1, last-1})){
			case2 = dp[{head+1, last-1}] + arr[last] - arr[head];
		}
		else{
			case2 = solve(head+1, last-1);
		}
	}
	else{ // z takes last-1
		if(dp.count({head, last-2})){
			case2 = dp[{head, last-2}] + arr[last] - arr[last-1];
		}
		else{
			case2 = solve(head, last-2);
		}
	}
	
	dp.insert({{head,last}, 0});
	moves.insert({{head,last}, 0});
	if(case1 >= case2){
		moves[{head, last}] = 1;
		return (dp[{head, last}] = case1);
	}
	else{
		moves[{head, last}] = 2;
		return (dp[{head, last}] = case2);
	}
	
	return -1;
}

int main(){
	IOS
	lli i;
	lli n, ni;

	//cin >> n;
	n = 1000;
	//dp.resize(n, vector<lli>(n, 0));
	for(i = 0; i < 2*n; i++){
		//cin >> ni;
		ni = i%9;
		arr.push_back(ni);
		total += ni;
	}
	
	if(solve(0, 2*n-1) >= 0){
		cout << "Marichka" << endl;
		int head = 0, last = 2*n-1;
		for(i = 0; i < n; i++){
			if(moves[{head, last}] == 1){
				cout << "L"; // m takes head
				if(arr[head+1] >= arr[last]){ // z takes head+1
					head = head + 2;
					last = last;
				}
				else{ // z takes last
					head = head + 1;
					last = last - 1;
				}
			}
			else{ // if(moves[{head, last}] == 2)
				cout << "R"; // m takes last
				if(arr[head] >= arr[last-1]){ // z takes head+1
					head = head + 1;
					last = last - 1;
				}
				else{ // z takes last
					head = head;
					last = last - 2;
				}
			}
		}
	}
	else{
		cout << "Zenyk" << endl;
	}
	
	cout << endl << endl << cnt << endl;
	
	return 0;
}
