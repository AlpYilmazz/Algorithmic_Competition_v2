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

//vector<vector<lli>> dp;
vector<lli> arr;
lli point[2] = {0, 0};
vector<char> moves;
bool m_wins = false;
lli total = 0;

lli i = 0;
void solve(lli player, lli head, lli last){ // 0m 1z, 
	i++;
	if(point[1] > total/2){
		return;
	}
	if(head == last){
		point[player] += arr[head];
		/*cout << "case " << i << ": " << endl;
		cout << "\t" << "p0 = " << point[0] << endl;
		cout << "\t" << "p1 = " << point[1] << endl;*/
		if(point[0] >= point[1]){
			//m_wins = true;
			cout << "Marichka" << endl;
			for(auto m : moves){
				cout << m;
			}
				cout << endl;
		}
		point[player] -= arr[head];
		return;
	}
/*
4
7 10 4 0 2 5 4 7
*/
	
	
	if(player == 1){
		if(arr[head] >= arr[last]){
			point[1] += arr[head];
			solve(0, head+1, last);
			if(m_wins) return;
			point[1] -= arr[head];
		}
		else{
			point[1] += arr[last];
			solve(0, head, last-1);
			if(m_wins) return;
			point[1] -= arr[last];
		}
	}
	else{ // if(player == 0)
		point[0] += arr[head];
		moves.push_back('L');
		solve(1, head+1, last);
		if(m_wins) return;
		point[0] -= arr[head];
		moves.pop_back();
		
		point[0] += arr[last];
		moves.push_back('R');
		solve(1, head, last-1);
		if(m_wins) return;
		point[0] -= arr[last];
		moves.pop_back();
	}
}

int main(){
	IOS
	lli i;
	lli n, ni;
	
	cin >> n;
	//dp.resize(n, vector<lli>(n, 0));
	for(i = 0; i < 2*n; i++){
		cin >> ni;
		arr.push_back(ni);
		total += ni;
	}
	
	solve(0, 0, 2*n-1);
	
	/*if(m_wins){
		cout << "Marichka" << endl;
		for(auto m : moves){
			cout << m;
		}
		cout << endl;
	}
	else{
		cout << "Zenyk" << endl;
	}*/
	
	return 0;
}
