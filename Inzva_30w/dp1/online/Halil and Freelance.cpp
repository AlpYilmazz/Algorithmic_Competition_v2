#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> jobs;
vector<int> length;

int main() {
    int i, j;
    int ni;
    int n;
    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> ni;
        jobs.push_back(ni);
    }
    length.resize(n, 1);
    for(i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            if(jobs[j] < jobs[i]){
                length[i] = max(length[i], length[j]+1);
            }
        }
    }
    
    int longest = 1;
    for(i = 0; i < length.size(); i++){
        longest = max(longest, length[i]);
    }
    
    cout << longest << endl;
    
    return 0;
}
