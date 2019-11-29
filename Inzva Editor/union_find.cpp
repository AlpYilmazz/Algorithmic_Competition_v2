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

#define N 100000

vector<int> ancestor(N);

int find(int k){
	if(ancestor[k] == k){
		return k;
	}
	return ancestor[k] = find(ancestor[k]);
	// return find(ancestor[k]);
}

int Union(int a, int b){ // find(a) -> find(b)
	ancestor[find(a)] = find(b);
}

void init_DSU{
	for(int i = 0; i < N; i++){
		ancestor[i] = i;
	}
}

int main(){
	IOS
	
	
	return 0;
}
