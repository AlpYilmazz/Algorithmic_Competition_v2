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

#define N 100005

class node{
	public:
		lli val;
		
		node(){
			val = 0;
		}
		node(lli x){
			val = x;
		}
};

vector<lli> arr(N, 0);
vector<node> tree(4*N, node());
vector<lli> lazy(4*N, 0);
lli n;

void upd_node(node& nd, lli new_val){
	nd.val += new_val;
}

node merge(node& n1, node& n2){
	node temp(n1.val + n2.val);
	return temp;
}

void build(lli ind, lli l, lli r){
	if(l == r){
		upd_node(tree[ind], arr[ind]);
		return;
	}

	lli mid = (l + r) / 2;

	build(2*ind, l, mid);
	build(2*ind + 1, mid+1, r);

	tree[ind] = merge(tree[2*ind], tree[2*ind+1]);
}

void update(lli ind, lli l, lli r, lli lw, lli rw, lli val){
	if(lazy[ind] != 0){
		lli update_by = (r - l + 1) * lazy[ind];
		upd_node(tree[ind], update_by);
		
		if(l != r){
			lazy[2*ind] += lazy[ind];
			lazy[2*ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if(rw < l || r < lw){
		return;
	}
	if(lw <= l && r <= rw){
		lazy[ind] += val;
		lli update_by = (r - l + 1) * lazy[ind];
		upd_node(tree[ind], update_by);

		if(l != r){
			lazy[2*ind] += lazy[ind];
			lazy[2*ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
		return;
	}

	lli mid = (l + r) / 2;

	update(2*ind, l, mid, lw, rw, val);
	update(2*ind + 1, mid+1, r, lw, rw, val);

	tree[ind] = merge(tree[2*ind], tree[2*ind + 1]);
}

node query(lli ind, lli l, lli r, lli lw, lli rw){
	if(rw < l || r < lw){
		node temp(0);
		return temp;
	}
	
	if(lazy[ind] != 0){
		lli update_by = (r - l + 1) * lazy[ind];
		upd_node(tree[ind], update_by);
		if(l != r){
			lazy[2*ind] += lazy[ind];
			lazy[2*ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if(lw <= l && r <= rw){
		return tree[ind].val;
	}
	
	lli mid = (l + r) / 2;

	node lnd = query(2*ind, l, mid, lw, rw);
	node rnd = query(2*ind + 1, mid+1, r, lw, rw);

	return merge(lnd, rnd);
}

void build(lli size){
	build(1, 1, size);
}

void update(lli lw, lli rw, lli val){
	update(1, 1, n, lw, rw, val);
}

lli query(lli lw, lli rw){
	node temp = query(1, 1, n, lw, rw);
	return temp.val;
}

int main(){
	IOS
	lli i;
	lli q;

	cin >> n >> q;
	for(i = 1; i <= n; i++){
		cin >> arr[i];
	}
	build(n);
	while(q--){
		lli type, l, r;

		cin >> type >> l >> r;

		if(type == 1){
			lli add;
			cin >> add;
			update(l, r, add);
		}
		else{
			lli ans = query(l, r);
			cout << ans << endl;
		}
	}

	for(i = n; i <= 2*n - 1; i++){
		cout << tree[i].val << " ";
	}
	cout << endl;

	return 0;
}
