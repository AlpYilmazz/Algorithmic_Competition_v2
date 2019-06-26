#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef pair<int,int> p_ii;

// Only this function is my code
int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int,int>>> adj;
    priority_queue< p_ii, vector<p_ii>, greater<p_ii> > pq;
    vector<bool> visited;
    int i;
    int total_weight = 0;
    
    adj.resize(n+1);
    visited.resize(n+1, false);
    for(i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int node = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        total_weight += w;
        
        for(auto u : adj[node]){
            pq.push(make_pair(u.second, u.first));
        }
    }
    
    return total_weight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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
