#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
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

/*struct CustomCompare{
    bool operator(tuple<int,int,int> before, tuple<int,int,int> after){
        if(get<2>(before) == get<2>(after)){
            int bef = get<0>(before) + get<1>(before) + get<2>(before);
            int af = get<0>(after) + get<1>(after) + get<2>(after);
            return bef < af;
        }
        else{
            return get<2>(before) < get<2>(after);
        }
    }
};

priority_queue<tuple<int,int,int>> pq;*/

#define N 3001

int ancestor[N];

int find(int k){
    if(ancestor[k] == k) return k;
    return (ancestor[k] = find(ancestor[k]));
}

void MakeUnion(int a, int b){
    ancestor[find(a)] = find(b);
}

void init_ancestor(){
    for(int i = 0; i < N; i++){
        ancestor[i] = i;
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
    int total = 0;
    init_ancestor();
    vector<int> g_sorted_i;
    for(int i = 0; i < g_from.size(); i++){
        g_sorted_i.push_back(i);
    }
    // sort();
    //cout << total;
    sort(g_sorted_i.begin(), g_sorted_i.end(),
        [&g_from, &g_to, &g_weight](const int &a, const int &b){
            if(g_weight[a] == g_weight[b]){
                int a_w = g_from[a] + g_to[a];
                int b_w = g_from[b] + g_to[b];
                return a_w < b_w;
            }
            else{
                return g_weight[a] < g_weight[b];
            }
        });
    //cout << total;
    for(auto i : g_sorted_i){
        if(find(g_from[i]) != find(g_to[i])){
            total += g_weight[i];
            MakeUnion(g_from[i], g_to[i]);
        }
    }
    return total;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

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

    int res = kruskals(g_nodes, g_from, g_to, g_weight);
    
    //fout << res << endl;
    cout << res << endl;
    // Write your code here.

    //fout.close();

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
