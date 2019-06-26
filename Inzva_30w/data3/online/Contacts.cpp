#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl

#define ALPHABET_SIZE 26

class TrieNode{
	public:
		TrieNode* children[ALPHABET_SIZE];
		bool isEndOfWord;
		lli countBelow;
		TrieNode(){
			isEndOfWord = false;
			countBelow = 0;
			for(int i = 0; i < ALPHABET_SIZE; i++){
				children[i] = NULL;
			}
		}
};

void insert(TrieNode* root, string key){
	TrieNode* traverse = root;
	for(int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if(!traverse->children[index]){
			traverse->children[index] = new TrieNode;
		}
		traverse->countBelow += 1;
		traverse = traverse->children[index];
	}
	traverse->isEndOfWord = true;
}

lli search(TrieNode* root, string key){
	TrieNode* traverse = root;
	for(int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if(!traverse->children[index]){
			return 0;
		}
		traverse = traverse->children[index];
	}
	return traverse->countBelow;
}

int main(){
	IOS
	lli i;
	lli n;
	string type, str;
	TrieNode* root = new TrieNode;
	
	cin >> n;
	for(i = 0; i < n; i++){
		type.clear();
		str.clear();
		cin >> type >> str;
		if(type[0] == 'a'){
			insert(root, str);
		}
		else{ // if(type[0] == 'f')
			lli count = search(root, str);
			cout << count << endl;
		}
	}
	
	delete root;
	
	return 0;
}
