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

#define N 200001
#define LOGN 9
#define INF 2000000007

class node{
	public:
		int best;
		vector<int> mn;
		
		node(){
			best = INF;
			mn.resize(LOGN, INF);
		}
		int& operator[](int i){
			return mn[i];
		}
};

vector<int> arr(N);
vector<node> segTree(4*N);

void upd_node(node& nd, int val){
	int temp = val;
	for(int i = 0; i < LOGN; i++){
		if(temp % 10 != 0){
			nd[i] = min(nd[i], val);
		}
		temp /= 10;
	}
}

node merge(node& n1, node& n2){
	node new_node;
	new_node.best = min(n1.best, n2.best);
	for(int i = 0; i < LOGN; i++){
		new_node[i] = min(n1[i], n2[i]);
		if(n1[i] < INF && n2[i] < INF){
			new_node.best = min(new_node.best, n1[i] + n2[i]);
		}
	}
	return new_node;
}

void build(int ind, int l, int r){
	if(l == r){
		segTree[ind] = node();
		upd_node(segTree[ind], arr[l]);
		return;
	}

	int mid = (l + r) / 2;
	build(2*ind, l, mid);
	build(2*ind + 1, mid+1, r);
	segTree[ind] = merge(segTree[2*ind], segTree[2*ind + 1]);
}

void update(int ind, int l, int r, int x, int val){
	if(l > x || r < x){
		return;
	}
	if(l == x && r == x){
		segTree[ind] = node();
		upd_node(segTree[ind], val);
		return;
	}

	int mid = (l + r) / 2;
	update(2*ind, l, mid, x, val);
	update(2*ind + 1, mid+1, r, x, val);
	segTree[ind] = merge(segTree[2*ind], segTree[2*ind + 1]);
}

node query(int ind, int l, int r, int L, int R){
	if(l > R || r < L){
		node temp = node();
		return temp;
	}
	if(l >= L && r <= R){
		return segTree[ind];
	}

	int mid = (l + r) / 2;
	node qn1 = query(2*ind, l, mid, L, R);
	node qn2 = query(2*ind + 1, mid+1, r, L, R);
	return merge(qn1, qn2);
}

int main(){
	IOS
	int i;
	int n, m;
	
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		cin >> arr[i];
	}
	build(1, 1, n);
	while(m--){
		int type, x, y;

		cin >> type >> x >> y;
		if(type == 1){
			update(1, 1, n, x, y);
		}
		else{
			node ans_nd = query(1, 1, n, x, y);
			int ans = (ans_nd.best == INF) ? -1 : ans_nd.best;
			cout << ans << endl;
		}
	}
	
	return 0;
}
