#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getCost' function below.
 *
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

vector<vector<pair<int,int>>> adj;

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
    // Print your answer within the function and return nothing
    int i;
    adj.resize(g_nodes+1);
    for(i = 0; i < g_from.size(); i++){
        adj[g_from[i]].push_back(make_pair(g_to[i], g_weight[i]));
        adj[g_to[i]].push_back(make_pair(g_from[i], g_weight[i]));
    }
    vector<int> dist(g_nodes+1, INT_MAX/2);
    vector<bool> visited(g_nodes+1, false);
    dist[1] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push(make_pair(0, 1));
    
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        
        for(auto it : adj[node]){
            int u = it.first;
            int w = it.second - d;
            if(w < 0) w = 0;
            if(dist[node] + w < dist[u]){
                dist[u] = dist[node] + w;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
    
    if(dist[g_nodes] == INT_MAX/2){
        cout << "NO PATH EXISTS" << endl;
    }
    else{
        cout << dist[g_nodes] << endl;
    }
}

int main()
{
    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    getCost(g_nodes, g_from, g_to, g_weight);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
