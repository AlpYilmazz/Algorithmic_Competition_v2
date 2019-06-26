#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

bool compatible(char l, char r){
    if(l == '('){
        if(r == ')'){
            return true;
        }
    }
    else if(l == '{'){
        if(r == '}'){
            return true;
        }
    }
    else if(l == '['){
        if(r == ']'){
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int i;
        bool flag = false;
        string bra;
        cin >> bra;
        
        stack<char> s;
        for(i = 0; i < bra.length(); i++){
            if(bra[i] == '(' || bra[i] == '{' || bra[i] == '['){
                s.push(bra[i]);
            }
            else{
                if(s.empty()){
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
                else{
                    char a = s.top();
                    s.pop();
                    if(!compatible(a, bra[i])){
                        cout << "NO" << endl;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag){
            continue;
        }
        if(!s.empty()){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
