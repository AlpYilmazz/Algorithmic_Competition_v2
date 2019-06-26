#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Only this function is my code
int pylons(int k, vector<int> arr){
    int i, j;
    int right_most, last_one = -1, plant = arr.size(), temp, total = 0;
    
    for(i = 0; i < arr.size(); i++){
        if(arr[i] == 1){
            last_one = i;
        }
        if(i >= plant + k || i == 0){
            temp = total;
            right_most = i + k - 1;
            if(right_most >= arr.size()){
                right_most = arr.size() - 1;
            }
            for(j = right_most; j >= i; j--){
                if(arr[j] == 1){
                    total++;
                    plant = j;
                    break;
                }
            }
            if(total == temp && last_one != -1){
                if(i < last_one + k){
                    total++;
                    plant = last_one;
                }
                else{
                    return -1;
                }
            }
            else if(total == temp && last_one == -1){
                return -1;
            }
        }
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pylons(k, arr);

    fout << result << "\n";

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
