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
vector<p_ii> split[2]; // index, type

bool can_put(lli si, lli type){
	if(split[si].size() == 0){
		return true;
	}
	return (split[si][split[si].size()-1].second != type);
}

int main(){
	IOS
	lli i;
	lli n;
	
	cin >> n;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(i = 0; i < n; i++){
		if(i != n-1){
			if(can_put(0, arr[i]) && can_put(1, arr[i])){
				if(arr[i] == arr[i+1]){
					split[0].push_back(make_pair(i, arr[i]));
				}
				else{
					if(!can_put(0, arr[i+1])){
						split[0].push_back(make_pair(i, arr[i]));
					}
					else{
						split[1].push_back(make_pair(i, arr[i]));
					}
				}
			}
			else if(can_put(0, arr[i])){
				split[0].push_back(make_pair(i, arr[i]));
			}
			else if(can_put(1, arr[i])){
				split[1].push_back(make_pair(i, arr[i]));
			}
			else{
				cout << -1 << endl;
				return 0;
			}
		}
		else{
			if(can_put(0, arr[i])){
				split[0].push_back(make_pair(i, arr[i]));
			}
			else if(can_put(1, arr[i])){
				split[1].push_back(make_pair(i, arr[i]));
			}
			else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	for(lli si = 0; si < 2; si++){
		cout << split[si].size() << endl;
		for(i = 0; i < (lli) split[si].size(); i++){
			cout << split[si][i].first+1;
			if(i != (lli) split[si].size()-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}
