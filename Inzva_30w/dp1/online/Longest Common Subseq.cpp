#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Only this function is my code
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b){
    int i, j;
    int L[a.size()+1][b.size()+1];
    
    for(i = 0; i <= a.size(); i++){
        for(j = 0; j <= b.size(); j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]){
                L[i][j] = 1 + L[i-1][j-1];
            }
            else{
                L[i][j] = max( L[i][j-1], L[i-1][j] );
            }
        }
    }
    
    int index = L[a.size()][b.size()];
    vector<int> lcs(index);
    
    i = a.size(); j = b.size();
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs[index-1] = a[i-1];
            i--; j--; index--;
        }
        else if(L[i-1][j] > L[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return lcs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
