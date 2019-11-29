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

stack<char> s;

int main(){
	IOS
	lli i, j;
	string w;

	cin >> w;
	
	if(w.size() % 2 == 1){
		cout << "NO" << endl;
		return 0;
	}

	s.push(w[0]);
	for(i = 1; i < w.size(); i++){
		if(s.empty()){
			s.push(w[i]);
		}
		else if(s.top() == w[i]){
			s.pop();
		}
		else{
			s.push(w[i]);
		}
	}

	if(s.empty()){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	


	return 0;
}
