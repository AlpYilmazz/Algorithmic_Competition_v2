#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define INF 1000000000000

typedef long long int lli;

// Only this function is my code
vector<lli> shortestReach(lli n, vector<vector<int>> edges, lli s) {
    vector<vector<pair<lli,lli>>> adj(n+1);
    vector<lli> dist(n+1, INF);
    vector<bool> visited(n+1,false);
    
    for(auto u : edges){
        adj[u[0]].push_back(make_pair(u[1], u[2]));
        adj[u[1]].push_back(make_pair(u[0], u[2]));
    }
    
    priority_queue< pair<lli,lli>, vector<pair<lli,lli>>, greater<pair<lli,lli>> > pq;
    
    dist[s] = 0;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(auto it : adj[node]){
            lli u = it.first;
            lli w = it.second;
            if(dist[node] + w < dist[u]){
                dist[u] = dist[node] + w;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
    
    
    vector<lli> result;
    for(int i = 1; i < dist.size(); i++){
        if(i == s) continue;
        if(dist[i] == INF){
            result.push_back(-1);
        }
        else{
            result.push_back(dist[i]);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<lli> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
