#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

vector<int> primes;

lli numberizer(vector<lli> fac){
	lli num = 0;
	for(unsigned int i = 0; i < fac.size(); i++){
		num += pow(primes[i], fac[i]);
	}
	return num;
}

struct CustomCompare{
	bool operator()(vector<lli> v1, vector<lli> v2){
		lli val1 = 0, val2 = 0;
		for(unsigned int i = 0; i < primes.size(); i++){
			val1 += pow(primes[i], v1[i]);
			val2 += pow(primes[i], v2[i]);
		}
		return val2 < val1;
	}
};

priority_queue<vector<lli>, vector<vector<lli>>, CustomCompare> pq;
unordered_set<lli> in;

int main(){
	IOS
	
	/*primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	
	vector<lli> temp;
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(0);
	pq.push(temp);
	temp[0] = 0;
	temp[1] = 1;
	pq.push(temp);
	
	vector<lli> den;
	den = pq.top();
	cout << den[0];*/
	
	int i;
	int k;
	int n, pi;
	cin >> n;
	
	for(i = 0; i < n; i++){
		cin >> pi;
		primes.push_back(pi);
	}
	cin >> k;
	
	vector<lli> temp;
	temp.resize(n, 0);
	pq.push(temp);
	in.insert(numberizer(temp));
	
	vector<lli> foo;
	vector<lli> bar;
	for(i = 0; i < k; i++){
		foo.clear();
		bar.clear();
		bar = pq.top();
		foo = bar;
		pq.pop();
		in.erase(numberizer(bar));
		for(unsigned int j = 0; j < bar.size(); j++){
			bar[j] += 1;
			if(!in.count(numberizer(bar))){
				pq.push(bar);
			}
			bar[j] -= 1;
		}
	}
	
	cout << numberizer(foo) << endl;
	
	return 0;
}
