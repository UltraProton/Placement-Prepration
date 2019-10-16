#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class disjoint_set{
    public:
    int n_set;
    vector<int> parent;
    vector<int> rank;

    disjoint_set(int n_set);
    void MAKESET(int u);
    void UNION(int u, int v);
    int FIND(int u);
};


bool cmp(const vector<int> &x, const vector<int> &y);

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

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    vector<vector<int>> G;
    for(int i=0;i<g_from.size();i++){
        G.push_back(vector<int>{g_from[i], g_to[i],g_weight[i]});
    }

    disjoint_set ds(g_nodes+5);
    //set to store edges in the mst
    set<vector<int>> mst;
    
    int min_cost=0;

    sort(G.begin(), G.end(), cmp);

    //for each vertex in the disjoint set call makeset
    for(int i=0;i<ds.n_set;i++){
        ds.MAKESET(i);
    }

    for(auto x:G){
        int p1= ds.FIND(x[0]);
        int p2= ds.FIND(x[1]);

        if(p1!=p2){
            min_cost+=x[2];
            mst.insert(x);

            ds.UNION(p1,p2);
        }
    }

    // cout<<"min cost: "<<min_cost<<endl;

    // for(auto x:mst){
    //     cout<<x[0]<<","<<x[1]<<","<<x[2]<<endl;
    // }

    // for(auto x:G){
    //     cout<<x[0]<<","<<x[1]<<","<<x[2]<<endl;
    // }
    return min_cost;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    // Write your code here.
    fout << res << "\n"; // ! fout needs to be used for printing on stdout
    fout.close();

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



bool cmp(const vector<int> &x, const vector<int> &y){
    if(x[2] < y[2] ){
        return true;
    }
    else{
        return false;
    }
}

disjoint_set :: disjoint_set(int x){
    n_set=x;
    parent= vector<int>(n_set,-1);
    rank =vector<int>(n_set,0);
}

void disjoint_set :: MAKESET(int u){
    parent[u]=u;
    rank[u]=0;
}

int disjoint_set :: FIND(int u){
    if(parent[u]==u){
        return u;
    }
    else{
        parent[u]= FIND(parent[u]);
        return parent[u];
    }
}
void disjoint_set :: UNION(int u, int v){
    int x=FIND(u);
    int y=FIND(v);

    if(rank[x]>=rank[y]){
        parent[y]=x;
        if(rank[x]==rank[y]){
            rank[x]++;
        }
    }
    else{
        parent[x]=y;
    }
}


