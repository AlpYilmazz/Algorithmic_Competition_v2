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
#include <functional>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

//vector<p_ii> ns;
priority_queue<lli> maxPlus;
priority_queue< lli, vector<lli>, greater<lli> > minPlus;
priority_queue<lli> maxMinus;
priority_queue< lli, vector<lli>, greater<lli> > minMinus;

lli intify(string s){
	lli ans = 0;
	for(int i = 0; i < s.size(); i++){
		ans += s[i];
	}
	return ans;
}

int main(){
	IOS
	lli i, j;
	lli n;
	
	cin >> n;
	
	lli ata = intify("ata"), mert = intify("mert");
	
	//ns.push_back(make_pair(ata, mert));
	maxPlus.push(ata + mert);
	minPlus.push(ata + mert);
	maxMinus.push(ata - mert);
	minMinus.push(ata - mert);
	
	lli prevmax = -1;
	for(i = 0; i < n; i++){
		lli n, s;
		string name, sur;
		
		cin >> name >> sur;
		n = intify(name);
		s = intify(sur);
		
		maxPlus.push(n + s);
		minPlus.push(n + s);
		maxMinus.push(n - s);
		minMinus.push(n - s);
		
		lli maxhate = max(maxPlus.top() - minPlus.top()
						, maxMinus.top() - minMinus.top());
		
		/*for(j = 0; j < ns.size(); j++){
			lli hate = abs(ns[j].first - n)
						+ abs(ns[j].second - s);
			
			maxhate = max(hate, maxhate);
		}*/
		
		//maxhate = max(prevmax, maxhate);
		//ns.push_back(make_pair(n, s));
		
		cout << maxhate << endl;
		
		//prevmax = maxhate;
	}
	
	return 0;
}
