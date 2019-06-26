#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<vector<lli>> mx;
vector<vector<lli>> rotated_mx;

pair<lli, lli> put(lli i, lli j, lli r, lli rlw, lli rup, lli clw, lli cup){
    lli i, j;
    
    for(i = rlw, j = clw; i < rup-1; i++){
        if(r == 0){
            return pair<lli, lli>(i, j);
        }
        r--;
    }
    for(i = rup-1, j = clw; j < cup-1; j++){
        if(r == 0){
            return pair<lli, lli>(i, j);
        }
        r--;
    }
    for(i = rup-1, j = cup-1; i > rlw; i--){
        if(r == 0){
            return pair<lli, lli>(i, j);
        }
        r--;
    }
    for(i = rlw, j = cup-1; j > clw; j--){
        if(r == 0){
            return pair<lli, lli>(i, j);
        }
        r--;
    }
    if(r == 0){
        return pair<lli, lli>(i, j);
    }
}


pair<lli, lli> next(lli i, lli j, lli rlw, lli rup, lli clw, lli cup){
    
    if(i < rup-1 && j == clw){
        return pair<lli, lli>(i+1, j);
    }
    else if(i == rup-1 && j < cup-1){
        return pair<lli, lli>(i, j+1);
    }
    else if(i > rlw && j == cup-1){
        return pair<lli, lli>(i-1, j);
    }
    else if(i == rlw && j > clw){
        return pair<lli, lli>(i, j-1);
    }
    
}


void rotate(lli r, lli rlw, lli rup, lli clw, lli cup){ // [lw, up)
    lli i, j;
    pair<lli, lli> temp;
    
    temp = put(rlw, clw, r, rlw, rup, clw, cup);
    
    for(i = rlw+1, j = clw; i < rup-1; i++){
        rotated_mx[temp.first][temp.second];
        temp = next(temp.first, temp.second, rlw, rup, clw, cup);
    }
    for(i = rup-1, j = clw; j < cup-1; j++){
        rotated_mx[temp.first][temp.second];
        temp = next(temp.first, temp.second, rlw, rup, clw, cup);
    }
    for(i = rup-1, j = cup-1; i > rlw; i--){
        rotated_mx[temp.first][temp.second];
        temp = next(temp.first, temp.second, rlw, rup, clw, cup);
    }
    for(i = rlw, j = cup-1; j > clw; j--){
        rotated_mx[temp.first][temp.second];
        temp = next(temp.first, temp.second, rlw, rup, clw, cup);
    }
}

int main(){
    lli i, j;
    lli row, col, r;
    
    cin >> row >> col >> r;
    mx.resize(row, vector<lli>(col));
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            cin >> mx[i][j];
        }
    }
    
    return 0;
}
