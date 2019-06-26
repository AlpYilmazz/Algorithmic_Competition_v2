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

vector<stack<lli>> s(3);
lli sum[3] = {0};

void get_input(){
    lli i;
    lli n0, n1, n2;
    vector<lli> t;
    
    cin >> n0 >> n1 >> n2;
    
    t.resize(n0);
    for(i = 0; i < n0; i++){
        cin >> t[i];
    }
    for(i = n0-1; i >= 0; i--){
        s[0].push(t[i]);
        sum[0] += t[i];
    }
    
    t.clear(); t.resize(n1);
    for(i = 0; i < n1; i++){
        cin >> t[i];
    }
    for(i = n1-1; i >= 0; i--){
        s[1].push(t[i]);
        sum[1] += t[i];
    }
    
    t.clear(); t.resize(n2);
    for(i = 0; i < n2; i++){
        cin >> t[i];
    }
    for(i = n2-1; i >= 0; i--){
        s[2].push(t[i]);
        sum[2] += t[i];
    }
}

lli solve(){
    lli mn = min(sum[0], min(sum[1], sum[2]));
    while(true){
        while(sum[0] > mn){
            sum[0] -= s[0].top();
            s[0].pop();
        }
        mn = min(sum[0], mn);
        
        while(sum[1] > mn){
            sum[1] -= s[1].top();
            s[1].pop();
        }
        mn = min(sum[1], mn);
        
        while(sum[2] > mn){
            sum[2] -= s[2].top();
            s[2].pop();
        }
        mn = min(sum[2], mn);
        
        if(sum[0] == sum[1] && sum[1] == sum[2]){
            break;
        }
    }
    return sum[0];
}

int main(){
    IOS
    lli ans;
    
    get_input();
    ans = solve();
    
    cout << ans << endl;
    
    return 0;
}
