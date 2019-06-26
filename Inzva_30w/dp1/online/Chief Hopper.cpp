#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<lli> arr;

lli chiefHopper(){
    int i;
    double e = 0.0;
    for(i = arr.size()-1; i >= 0; i--){
        e = (e+(double)arr[i])/2.0;
        if(e < 0.0) e = 0.0;
    }
    if(e != (lli)e) return ((lli)e)+1;
    return (lli)e;
}

lli chiefHopper_int(){
    int i;
    int e = 0, e_temp;
    for(i = arr.size()-1; i >= 0; i--){
        //cout << e << " - ";
        e_temp = e;
        e = (e+arr[i])/2;
        if((e_temp+arr[i])%2 == 1) e++;
        if(e < 0.0) e = 0.0;
        //cout << e << " /// ";
    }
    //cout << endl;
    return e;
}

int main(){
    int i;
    lli ni;
    int n;
    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> ni;
        arr.push_back(ni);
    }
    
    //cout << chiefHopper() << endl;
    cout << chiefHopper_int() << endl;
    
    return 0;
}
