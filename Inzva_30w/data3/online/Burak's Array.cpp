#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define ALPHABET_SIZE 2
#define MAX_BIT 30

class TrieNode{
	public:
		TrieNode* children[ALPHABET_SIZE];
		TrieNode(){
			for(i = 0; i < ALPHABET_SIZE; i++){
				children[i] = NULL;
			}
		}
};

void insert(TrieNode* root, int num){
	TrieNode* traverse = root;
	for(lli i = 0; i < MAX_BIT; i++){
		if(traverse->children[num[i]]){
			
		}
	}
}

int main(){
	IOS
	lli i;
	lli n;
	lli t;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> t;
	}
	
	return 0;
}
