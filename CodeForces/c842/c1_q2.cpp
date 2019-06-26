#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lli;

double distance(double xi, double yi){
	return sqrt(xi*xi + yi*yi);
}

int main(){
	double r, d;
	lli n;
	lli ans = 0;
	
	scanf("%lf%lf", &r, &d);
	scanf("%lld", &n);
	while(n--){
		double xi, yi, ri;
		scanf("%lf%lf%lf", &xi, &yi, &ri);
		if(distance(xi, yi) - ri >= r-d
			&& distance(xi, yi) + ri <= r){
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
