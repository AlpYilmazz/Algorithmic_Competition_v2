#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<int> arr;

int main(){
	IOS
	int i;
	int n, ai;
	
	cin >> n;
	arr.push_back(0);
	for(i = 1; i <= n; i++){
		cin >> ai;
		arr.push_back(ai);
	}
	arr.push_back(1001);
	
	int seq = 1;
	int best = 0;
	for(i = 1; i < arr.size(); i++){
		if(arr[i] == arr[i-1] + 1){
			seq++;
		}
		best = max(best, seq);
		if(arr[i] != arr[i-1] + 1){
			seq = 1;
		}
	}
	
	if(best <= 2){
		cout << 0 << endl;
	}
	else{
		cout << best - 2 << endl;
	}
	
	return 0;
}
