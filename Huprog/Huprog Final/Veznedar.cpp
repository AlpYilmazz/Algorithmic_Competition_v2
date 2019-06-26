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

#define N 100001

vector<lli> line;
priority_queue<p_ii> pq;

lli tree[4*(N)] = {0};
vector<lli> arr;

void build(lli ind, lli l, lli r){
    if(l == r){
        tree[ind] = arr[l];
    }
    else{
        lli mid = (l+r) / 2;
        build(ind*2, l, mid);
        build(ind*2 + 1, mid+1, r);
        tree[ind] = tree[ind*2] + tree[ind*2 + 1];
    }
}

lli query(lli ind, lli l, lli r, lli lw, lli rw){
    if(r < lw || rw < l){
        return 0;
    }
    if(lw <= l && r <= rw){
        return tree[ind];
    }
    lli mid = (l+r) / 2;
    
    return query(ind*2, l, mid, lw, rw) + query(ind*2 + 1, mid+1, r, lw, rw);
}

void update(lli ind, lli l, lli r, lli x, lli val){
    if(x < l || r < x){
        return;
    }
    if(l == x && r == x){
        tree[ind] = val;
        return;
    }
    lli mid = (l+r) / 2;
    
    update(ind*2, l, mid, x, val);
    update(ind*2 + 1, mid+1, r, x, val);
    tree[ind] = tree[ind*2] + tree[ind*2 + 1];
}

lli solve(){
	lli head = 1;
	lli gayme = 0;
	lli n = line.size()-1;
	while(!pq.empty()){
		p_ii rich = pq.top();
		pq.pop();
		
		lli gone;
		lli gayme_plus;
		if(rich.second > head){
			gone = query(1, 1, n, head, rich.second);
			gayme_plus = rich.second - head;
			gayme_plus++;
		}
		else{
			gone = query(1, 1, n, 1, rich.second);
			gone += query(1, 1, n, head, n);
			gayme_plus = rich.second - 1;
			gayme_plus += n - head;
			gayme_plus++;
		}
		
		gayme += gayme_plus - gone;
		
		head = (rich.second)%n + 1;
		update(1, 1, n, rich.second, 1);
	}
	
	return gayme;
}


int main(){
	IOS
	lli i;
	lli n;
	
	cin >> n;
	line.resize(n+1);
	for(i = 1; i <= n; i++){
		cin >> line[i];
		pq.push(make_pair(line[i], i));
	}

	lli ans = solve();
	
	cout << ans << endl;
	
	return 0;
}
