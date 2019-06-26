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

vector<pair<p_ii, lli>> s;
vector<pair<p_ii, lli>> m;
set<lli> done;

struct customCompare{
	bool operator()(pair<p_ii, lli> &a, pair<p_ii, lli> &b){
		if(a.first.first < b.first.first){
			return true;
		}
		else if(a.first.first == b.first.first){
			if(a.first.second > b.first.second){
				return true;
			}
			else if(a.first.second == b.first.second){
				return a.second < b.second;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
		return false;
	}
};

int main(){
	IOS
	lli i, j, k;
	lli n;
	lli li, ri, mi;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> li >> ri;
		mi = (li + ri)/2;
		s.push_back(make_pair(make_pair(li, mi), i));
		m.push_back(make_pair(make_pair(mi, ri), i));
	}
	if(n == 1){
		cout << "NO" << endl;
		return 0;
	}
	
	sort(s.begin(), s.end(), customCompare());
	sort(m.begin(), m.end(), customCompare());
	
	/*for(i = 0; i < s.size(); i++){
		cout << s[i].first.first << " ";
		cout << s[i].first.second << endl;
	}
	cout << "----------------------------" << endl;
	for(i = 0; i < m.size(); i++){
		cout << m[i].first.first << " ";
		cout << m[i].first.second << endl;
	}*/
	
	lli t = 0;
	lli beg, end;
	if(true){
		while(1){
			beg = s[t].first.first;
			end = s[t].first.second;
			done.insert(s[t].second);
			bool fin = false;
			for(i = 0; i < m.size(); i++){
				if(!done.count(m[i].second)){
					if(m[i].first.first > end){
						// ilk yarýdan almaya geç
						for(j = 0; j < s.size(); j++){
							if(!done.count(s[j].second)){
								if(s[j].first.first <= end){
									done.insert(s[j].second);
									end = s[j].first.second;
									break;
								}
								else{
									fin = true;
									t = j;
								}
								/*if(j == s.size()-1){
									//cout << "NO"<< endl;
									//return 0;
								}*/
							}
						}
						i--;
					}
					else{ // burdan al (son yarý)
						done.insert(m[i].second);
						end = m[i].first.second;
					}
				}
				
				if(fin){
					break;
				}
			}
			if(done.size() == n){
				break;
			}
		}
	}
	
	if(end < m[m.size()-1].first.second){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	
	return 0;
}
