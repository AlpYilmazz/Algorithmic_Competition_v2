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
#define MAX_BIT 40

vector<lli> arr;
vector<lli> prefix;
vector<lli> suffix;

class TrieNode{
	public:
		TrieNode* children[ALPHABET_SIZE];
		lli endNum;
		TrieNode(){
			endNum = -1;
			for(int i = 0; i < ALPHABET_SIZE; i++){
				children[i] = NULL;
			}
		}
};

void InsertAllSuffix(TrieNode* root){
	for(lli i = 0; i < suffix.size(); i++){
		vector<int> num(MAX_BIT);
		lli suf = suffix[i];
		for(int j = 0; j < num.size(); j++){
			num[num.size()-1 - j] = suf % 2;
			suf /= 2;
		}
		
		TrieNode* traverse = root;
		for(int j = 0; j < num.size(); j++){
			if(!traverse->children[num[j]]){
				traverse->children[num[j]] = new TrieNode;
			}
			traverse = traverse->children[num[j]];
		}
		traverse->endNum = suffix[i];
	}
}

lli FindMaxXOR(TrieNode* root){
	lli mx = 0;
	for(lli i = 0; i < prefix.size(); i++){
		vector<int> num(MAX_BIT);
		lli pre = prefix[i];
		for(int j = 0; j < num.size(); j++){
			num[num.size()-1 - j] = pre % 2;
			pre /= 2;
		}
		
		TrieNode* traverse = root;
		for(int j = 0; j < num.size(); j++){
			lli one = 1;
			if(traverse->children[num[j]^one]){
				traverse = traverse->children[num[j]^one];
			}
			else if(traverse->children[num[j]]){
				traverse = traverse->children[num[j]];
			}
		}
        
        lli pt = prefix[i]^traverse->endNum;
        
        //debug(mx);
        //debug(traverse->endNum);
        //cout << "pre^traverse->endNum = " << pt << endl;
        //cout << "-------------------------------" << endl;
		
        mx = max(pt, mx);
	}
	return mx;
}

void BuildPrefix(){
	lli i, temp = 0;
	prefix.resize(arr.size());
	for(i = 0; i < arr.size(); i++){
		temp ^= arr[i];
		prefix[i] = temp;
	}
}

void BuildSuffix(){
	lli i, temp = 0;
	suffix.resize(arr.size());
	for(i = arr.size()-1; i >= 0; i--){
		temp ^= arr[i];
		suffix[i] = temp;
	}
}

int main(){
	IOS
	lli i;
	lli n, ni;
	lli ans;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> ni;
		arr.push_back(ni);
	}
	
	TrieNode* root = new TrieNode;
	
	BuildPrefix();
	BuildSuffix();
    /*for(i = 0; i < arr.size(); i++){
        cout << prefix[i] << " " << suffix[i] << endl;
    }*/
	InsertAllSuffix(root);
	ans = FindMaxXOR(root);
	
	cout << ans << endl;
	
	return 0;
}
