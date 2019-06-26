#include <bits/stdc++.h>

using namespace std;

vector<int> pfac;

int prime_exp(int num, int p){
    int exp = 0;
    int p_keep = p;
    while(num % p == 0){
        exp++;
        p *= p_keep;
    }
    return exp;
}

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void prime_facs(int num){
    int i, k;
    int count;
    for(i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            int i_comp = num / i;
            if(is_prime(i)){
                count = prime_exp(num, i);
                for(k = 0; k < count; k++){
                    pfac.push_back(i);
                }
            }
            if(is_prime(i_comp)){
                count = prime_exp(num, i_comp);
                for(k = 0; k < count; k++){
                    pfac.push_back(i_comp);
                }
            }
        }
    }
}

int sum_of_digits(int num){
    int sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int is_Smith(int num){
    int i;
    int sd_num, sd_fac = 0;
    sd_num = sum_of_digits(num);
    for(i = 0; i < pfac.size(); i++){
        sd_fac += sum_of_digits(pfac[i]);
    }
    if(sd_num == sd_fac) return 1;
    return 0;
}

int main(){
    int i;
    int n;
    cin >> n;
    prime_facs(n);
    /*for(i = 0; i < pfac.size(); i++){
        cout << pfac[i] << endl;
    }
    cout << "--" << endl;
    cout << n / 75 << "  " << is_prime(65837) << endl;
    cout << "--" << endl;*/
    cout << is_Smith(n) << endl;
}
