#include <iostream>
#include <cstdio>
#include <algorithm> // sort
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> p_ii;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x ": " << x << endl
int bug = 1;

// Structure to store information of a suffix 
struct suffix 
{ 
    lli index; // To store original index 
    lli rank[2]; // To store ranks and next rank pair 
}; 
  
// A comparison function used by sort() to compare two suffixes 
// Compares two pairs, returns 1 if first pair is smaller 
lli cmp(struct suffix a, struct suffix b) 
{ 
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): 
               (a.rank[0] < b.rank[0] ?1: 0); 
} 
  
// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
lli *buildSuffixArray(string &txt, lli n) 
{ 
    // A structure to store suffixes and their indexes 
    struct suffix suffixes[n]; 
  
    // Store suffixes and their indexes in an array of structures. 
    // The structure is needed to sort the suffixes alphabatically 
    // and maintain their old indexes while sorting 
    for (lli i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].rank[0] = txt[i] - 'a'; 
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
    } 
  
    // Sort the suffixes using the comparison function 
    // defined above. 
    sort(suffixes, suffixes+n, cmp); 
  
    // At this point, all suffixes are sorted according to first 
    // 2 characters.  Let us sort suffixes according to first 4 
    // characters, then first 8 and so on 
    lli ind[n];  // This array is needed to get the index in suffixes[] 
                 // from original index.  This mapping is needed to get 
                 // next suffix. 
    for (lli k = 4; k < 2*n; k = k*2) 
    { 
        // Assigning rank and index values to first suffix 
        lli rank = 0; 
        lli prev_rank = suffixes[0].rank[0]; 
        suffixes[0].rank[0] = rank; 
        ind[suffixes[0].index] = 0; 
  
        // Assigning rank to suffixes 
        for (lli i = 1; i < n; i++) 
        { 
            // If first rank and next ranks are same as that of previous 
            // suffix in array, assign the same new rank to this suffix 
            if (suffixes[i].rank[0] == prev_rank && 
                    suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = rank; 
            } 
            else // Otherwise increment rank and assign 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            } 
            ind[suffixes[i].index] = i; 
        } 
  
        // Assign next rank to every suffix 
        for (lli i = 0; i < n; i++) 
        { 
            lli nextindex = suffixes[i].index + k/2; 
            suffixes[i].rank[1] = (nextindex < n)? 
                                  suffixes[ind[nextindex]].rank[0]: -1; 
        } 
  
        // Sort the suffixes according to first k characters 
        sort(suffixes, suffixes+n, cmp); 
    } 
  
    // Store indexes of all sorted suffixes in the suffix array 
    lli *suffixArr = new lli[n]; 
    for (lli i = 0; i < n; i++) 
        suffixArr[i] = suffixes[i].index; 
  
    // Return the suffix array 
    return  suffixArr; 
} 
  
// A utility function to print an array of given size 
void printArr(lli arr[], lli n) 
{ 
    for (lli i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 



// Driver program to test above functions 
int main() 
{ 
    string txt;
    
    cin >> txt;
    lli n = (lli) txt.size(); 
    lli *suffixArr = buildSuffixArray(txt,  n); 
    //cout << "Following is suffix array for " << txt << endl; 
    //printArr(suffixArr, n);
    
    /*
    lli res = 0;
    for(lli i = logn; i >= 0; i--){
    	if(P[i][x] == P[i][y])
	}
    */
    delete[] suffixArr;
    
    return 0; 
} 
