#include <iostream>
#include <algorithm> // sort
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define INF 1e18

int main(){
	IOS
	int k;
	int n, pi;
	cin >> n;
	
	vector<lli> factors(n);
	for(int i = 0; i < n; i++){
		cin >> pi;
		factors[i] = pi;
	}
	cin >> k;
	
    vector<lli> elements(k);
    elements[0] = 1;
    vector<lli> nextIndex(factors.size());
    vector<lli> nextFrom(factors.size());
    for (int j = 0; j < factors.size(); j++) {
        nextFrom[j] = factors[j];
    }
    for (int i = 1; i < k; i++) {
        lli nextNumber = INF;
        for (int j = 0; j < factors.size(); j++) {
            if (nextFrom[j] < nextNumber) {
                nextNumber = nextFrom[j];
            }
        }
        elements[i] = nextNumber;
        for (int j = 0; j < factors.size(); j++) {
            if (nextFrom[j] == nextNumber) {
                nextIndex[j]++;
                nextFrom[j] = elements[nextIndex[j]] * factors[j];
            }
        }
    }
    cout << elements[k] << endl;
	
	return 0;
}
