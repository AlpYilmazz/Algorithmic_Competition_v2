#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr;

bool is_fib_v2(int x){
    int f = 1, s = 1, t;
    while(s < x){
        t = f + s;
        f = s;
        s = t;
    }
    if(s == x) return true;
    return false;
}

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int i;
    int n, t;
    int temp;
    cin >> n >> t;
    for(i = 0; i < n; i++){
        //cin >> temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }

    for(int n_t = 0; n_t < t; n_t++){
        int type, index;
        //cin >> type >> index;
        scanf("%d %d", &type, &index);
        index--;
        if(type == 1){
            if(is_fib_v2(arr[index])){
                cout << "Fibonacci" << endl;
            }
            else{
                cout << "Not Fibonacci" << endl;
            }
        }
        else if(type == 2){
            if(is_prime(arr[index])){
                cout << "Prime" << endl;
            }
            else{
                cout << "Not Prime" << endl;
            }
        }
        else if(type == 3){
            float cbrt = pow(arr[index], 1.0/3.0);
            //cout << cbrt << " - " << (int) cbrt << endl;
            if(cbrt - (int) cbrt == 0.0){
                cout << "Cube" << endl;
            }
            else{
                cout << "Not Cube" << endl;
            }
        }
    }
    
    return 0;
}
