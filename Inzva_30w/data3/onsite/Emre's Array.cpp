#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

int bug = 1;

#define N 200001

lli segTree[4*N] = {0};
lli lazy1[4*N] = {0};
lli lazy2[4*N] = {0};
vector<lli> arr;

void build(lli node, lli start, lli end){
	if(start == end){
		segTree[node] = arr[start];
	}
	else{
		lli mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node + 1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node + 1];
	}
}

// start-end => node's , l-r => query's
void update(lli node, lli  start, lli end, lli l, lli r){
	if(lazy1[node] != 0){
		lli n = end - start + 1;
		segTree[node] += ((n * (n+1)) / 2) * lazy1[node];
		if(start != end){
			lazy1[2*node]++;
			lazy1[2*node + 1]++;
		}
		lazy1[node] = 0;
	}
	if(lazy2[node] != 0){
		lli n = end - start + 1;
		segTree[node] += n * lazy2[node];
		if(start != end){
			lli tmid = (start + end) / 2;
			lazy2[2*node] += lazy2[node];
			lazy2[2*node + 1] += lazy2[node] + (tmid - start);
		}
		lazy2[node] = 0;
	}
	if(start > r || end < l){
		return;
	}
	if(l <= start && end <= r){
		lli n = end - start + 1;
		segTree[node] += ((n * (n+1)) / 2);
		segTree[node] += (start - l) * n;
		if(start != end){
			lazy1[2*node]++;
			lazy1[2*node + 1]++;
			lazy2[2*node + 1] += (start - l);
		}
		return;
	}
	
	lli mid = (start + end) / 2;
	update(2*node, start, mid, l, r);
	update(2*node + 1, mid + 1, end, l, r);
	tree[node] = tree[2*node] + tree[2*node + 1];
}

lli query(lli node, lli start, lli end, lli l, lli r){
	if(start > r || end < l){
		return 0;
	}
	if(lazy1[node] != 0){
		lli n = end - start + 1;
		segTree[node] += ((n * (n+1)) / 2) * lazy1[node];
		if(start != end){
			lazy1[2*node]++;
			lazy1[2*node + 1]++;
		}
		lazy1[node] = 0;
	}
	if(lazy2[node] != 0){
		lli n = end - start + 1;
		segTree[node] += n * lazy2[node];
		if(start != end){
			lli tmid = (start + end) / 2;
			lazy2[2*node] += lazy2[node];
			lazy2[2*node + 1] += lazy2[node] + (tmid - start);
		}
		lazy2[node] = 0;
	}
	if(l <= start && end <= r){
		return segTree[node];
	}
	
	lli mid = (start + end) / 2;
	return query(2*node, start, mid, l, r)
			+ query(2*node + 1, mid + 1, end, l, r);
}

int main(){
	IOS
	lli n, m;
	
	cin >> n >> m;
	
	arr.resize(n+1, 0);
	build(1, 1, n);
	
	while(m--){
		lli type, x, y;
		cin >> type >> x >> y;
		
		if(type == 1){
			update(1, 1, n, x, y);
		}
		else{ // if(type == 2)
			lli ans = query(1, 1, n, x, y);
			cout << ans << endl;
		}
	}
	
	return 0;
}
