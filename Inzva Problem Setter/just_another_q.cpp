#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define fi first
#define sec second

vector<vector<lli>> tree;
vector<lli> sub_count;
vector<lli> ans;

void dfs(lli node, lli parent){
	
	for(auto u : tree[node]){
		if(u != parent){
			dfs(u, node);
			sub_count[node] += sub_count[u];
		}
	}
	sub_count[node]++;
}

int main(){
	lli i;
	lli n, q;

	cin >> n >> q;
	tree.resize(n+1);
	sub_count.resize(n+1, 0);
	for(i = 0; i < n-1; i++){
		lli a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	lli root = 1;
	dfs(root, -1);

	while(q--){
		lli node;

		cin >> node;

		ans.push_back(sub_count[node]);
	}

	for(i = 0; i < (lli) ans.size(); i++){
		cout << ans[i] << endl;
	}


	return 0;
}

/*
8 8
1 3
1 5
3 4
3 7
3 8
5 6
5 2
1
2
3
4
5
6
7
8
*/
