#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli i;
    lli ni;
    lli n;
    vector<lli> cal;
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> ni;
        cal.push_back(ni);
    }
    sort(cal.begin(), cal.end());
    
    lli factor = 1, result = 0;
    for(i = cal.size()-1; i >= 0; i--){
        result += factor * cal[i];
        factor *= 2;
    }
    cout << result << endl;
    
    return 0;
}
