#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define mod 100000000000000000

lli bug = 1;

lli fexp(lli x, lli k){
    if(k == 0) return 1;
    if(k == 1) return x;
    
    lli t = fexp(x, k>>1);
    
    if((k&1) == 1) return (x * t * t) % mod;
    return (t * t) % mod;
}

lli LCA(lli x, lli y, lli Lx, lli Ly){
    lli i;
    if(Lx > Ly){ // y is the deepest
        swap(x, y);
        swap(Lx, Ly);
    }
    
    lli dif = Ly - Lx;
    y = y / (fexp(2, dif));
    if(x == y){
        return y;
    }
    
    for(i = 1; i <= Lx; i *= 2){
    }
    for( ; i >= 1; i /= 2){
        if(x/i != y/i){
            x = x/i;
            y = y/i;
        }
    }
    return x/2;
}

lli LCA_v2(lli x, lli y, lli Lx, lli Ly){
    unordered_set<lli> Sx;
    
    while(x != 0){
        Sx.insert(x);
        x /= 2;
    }
    while(y != 0){
        if(Sx.count(y)){
            return y;
        }
        y /= 2;
    }
    return -1;
}

int main(){
    IOS
    lli change = 1;
    lli q;
    cin >> q;
    while(q--){
        // init := even L -> B ; odd L -> R
        string type;
        lli i;
        lli x, y, lca;
        lli Lx, Ly, Llca, len;
        lli black, red;
        
        cin >> type;
        if(type[1] == 'i'){
            change *= -1;
        }
        else{
            cin >> x >> y;
            
            for(i = 1, Lx = 0; i <= x; i *= 2){
                Lx++;
            }
            for(i = 1, Ly = 0; i <= y; i *= 2){
                Ly++;
            }
            
            //lca = LCA(x, y, Lx, Ly);
            lca = LCA_v2(x, y, Lx, Ly);
            for(i = 1, Llca = 0; i <= lca; i *= 2){
                Llca++;
            }
            
            len = (Ly+Lx) - 2*Llca;
            black = (len+1)/2;
            red = (len+1)/2;
            
            if((len+1)%2 == 1){
                if(Lx % 2 == 0){
                    if(change == 1){
                        red++;
                    }
                    else{
                        black++;
                    }
                }
                else{
                    if(change == 1){
                        black++;
                    }
                    else{
                        red++;
                    }
                }
            }
            
            if(type[1] == 'b'){
                cout << black << endl;
            }
            else if(type[1] == 'r'){
                cout << red << endl;
            }
            else{
                lli node = len+1;
                debug(x);
                debug(y);
                debug(lca);
                debug(Lx);
                debug(Ly);
                debug(Llca);
                debug(len);
                debug(node);
                debug(black);
                debug(red);
            }
        }
    }
    
    return 0;
}
