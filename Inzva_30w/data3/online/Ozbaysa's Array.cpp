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

int block_size;

class Query{
	public:
		int l, r, ind;
		Query(int l, int r, int ind){
			this->l = l, this->r = r, this->ind = ind;
		}
		bool operator<(Query other) const{
			return make_pair(l / block_size, r) <
					make_pair(other.l / block_size, other.r);
		}
};

void del(int ind, vector<int> &A, vector<int> &F, int &num){
	if(F[A[ind]] == 1){
		num--;
	}
	F[A[ind]]--;
}

void add(int ind, vector<int> &A, vector<int> &F, int &num){
	if(F[A[ind]] == 0){
		num++;
	}
	F[A[ind]]++;
}

vector<int> solve(vector<int> &A, vector<Query> &q){
	int N = A.size();
	int M = *max_element(A.begin(), A.end());
	block_size = sqrt(N);
	sort(q.begin(), q.end());
	vector<int> F(M+1, 0);
	vector<int> ans(q.size(), 0);
	
	int l = 0, r = -1, num = 0;
	for(int i = 0; i < q.size(); i++){
		int nl = q[i].l, nr = q[i].r;
		
		while(l < nl) del(l++, A, F, num);
		while(l > nl) add(--l, A, F, num);
		while(r > nr) del(r--, A, F, num);
		while(r < nr) add(++r, A, F, num);
		
		ans[q[i].ind] = num;
	}
	return ans;
}

int main(){
	IOS
	int i;
	int n, m;
	vector<int> arr;
	vector<Query> q_arr;
	
	cin >> n >> m;
	arr.resize(n);
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		Query new_q(x, y, i);
		q_arr.push_back(new_q);
	}
	
	vector<int> ans = solve(arr, q_arr);
	
	for(auto u : ans){
		cout << u << endl;
	}
	
	return 0;
}
