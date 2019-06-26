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

priority_queue<p_ii> pq; // zaman, kasa indexi
vector<lli> kasa;
vector<lli> cust;

int main(){
	IOS
	lli i;
	lli n, m;
	
	cin >> n >> m;
	kasa.resize(n);
	cust.resize(m);
	for(i = 0; i < n; i++){
		cin >> kasa[i];
	}
	for(i = 0; i < m; i++){
		cin >> cust[i];
	}
	
	for(i = 0; i < (lli)kasa.size(); i++){
		if(i >= (lli)cust.size()){
			break;
		}
		pq.push(make_pair(-(kasa[i] * cust[i]), -i));
	}
	
	for( ; i < (lli)cust.size(); i++){
		p_ii temp = pq.top();
		pq.pop();
		
		lli curr_time = -temp.first;
		lli kasa_i = -temp.second;
		
		p_ii yeni = make_pair(-(curr_time + kasa[kasa_i]*cust[i]), -kasa_i);
		pq.push(yeni);
	}
	
	p_ii ans;
	while(!pq.empty()){
		ans = pq.top();
		pq.pop();
	}
	
	cout << -ans.first << endl;
	
	return 0;
}









