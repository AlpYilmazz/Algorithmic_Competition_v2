#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <functional>
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

#define N 20

vector<int> arr(N);

void init(){
	for(int i = 0; i < N; i++){
		arr[i] = N-1 - i;
	}
}

void print(){
	for(auto u : arr){
		cout << u << " ";
	}
	cout << endl << endl;
}

class custom_comparator_1{ // custom_comparator_1()
	public:
		bool operator()(const int &a, const int &b){
			return (a <= b);
		}
};

bool custom_comparator_3(const int &a, const int &b){
	return (a <= b);
}

int main(){
	IOS
	lli i;

	auto custom_comparator_2 = [](const auto &a, const auto &b){
		return (a <= b);
	};

	init();
	sort(arr.begin(), arr.end(), 
		[](const int &a, const int &b){
			return (a <= b);
		}
	);
	print();

	init();
	sort(arr.begin(), arr.end(), custom_comparator_1());
	print();
	
	init();
	sort(arr.begin(), arr.end(), custom_comparator_2);
	print();

	init();
	sort(arr.begin(), arr.end(), custom_comparator_3);
	print();

	return 0;
}
