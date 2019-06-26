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

#define N 200001

int bug = 1;

lli tree[4*(N)] = {0};
vector<p_ii> lazy[4*(N)];
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

// start-end => node's , l-r => query's
lli query(lli node, lli start, lli end, lli l, lli r){
    if(start > r || end < l){
    	return 0;
	}
	if(lazy[node].size() != 0){
		for(auto lzy : lazy[node]){
			tree[node] += ((lzy.second)*(lzy.second+1)) / 2
    					- ((lzy.first-1)*(lzy.first)) / 2;
    		if(start != end){
    			lli lazy_mid = (lzy.first + lzy.second) / 2;
    			lazy[2*node].push_back(make_pair(lzy.first, lazy_mid));
    			lazy[2*node + 1].push_back(make_pair(lazy_mid + 1, lzy.second));
			}
		}
		lazy[node].clear();
	}
	if(l <= start && end <= r){
		return tree[node];
	}
    
    lli mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) + query(2*node +1, mid+1, end, l, r);
}

// start-end => node's , l-r => query's
void update(lli node, lli start, lli end, lli l, lli r){
    if(lazy[node].size() != 0){
    	for(auto lzy : lazy[node]){
    		tree[node] += ((lzy.second)*(lzy.second+1)) / 2
    					- ((lzy.first-1)*(lzy.first)) / 2;
    		if(start != end){
    			lli lazy_mid = (lzy.first + lzy.second) / 2;
    			lazy[2*node].push_back(make_pair(lzy.first, lazy_mid));
    			lazy[2*node + 1].push_back(make_pair(lazy_mid + 1, lzy.second));
			}
		}
		lazy[node].clear();
	}
	if(start > r || end < l){
		return;
	}
	if(l <= start && end <= r){
		lli lazy_f = 1 + (start-l);
		lli lazy_s = lazy_f + (end - start);
		tree[node] += ((lazy_s)*(lazy_s + 1)) / 2
    				- ((lazy_f - 1)*(lazy_f)) / 2;
    	if(start != end){
    		lli lazy_mid = (lazy_f + lazy_s) / 2;
    		lazy[2*node].push_back(make_pair(lazy_f, lazy_mid));
			lazy[2*node + 1].push_back(make_pair(lazy_mid + 1, lazy_s));
		}
        return;
	}
    
    //debug(bug);
    //cout << "--" << endl;
    
    lli mid = (start + end) / 2;
    update(2*node, start, mid, l, r);
    update(2*node + 1, mid+1, end, l, r);
    
    //debug(bug);
    
    tree[node] = tree[2*node] + tree[2*node + 1];
    
    //debug(bug);
}

int main(){
	IOS
	lli n, m;
	
	cin >> n >> m;
	arr.resize(n+1, 0);
	
	build(1, 1, n);
	arr.clear();
    /*for(int i = 0; i < 4*n; i++){
        cout << tree[i] << endl;
    }*/
	
	while(m--){
		lli type, x, y;
		cin >> type >> x >> y;
		
        //debug(x);
		if(type == 1){
			update(1, 1, n, x, y);
            //debug(x);
            /*for(int i = 0; i < 4*n; i++){
                cout << tree[i] << endl;
            }*/
		}
		else{ // if(type == 2)
			lli ans = query(1, 1, n, x, y);
			cout << ans << endl;
		}
	}
	
	return 0;
}
