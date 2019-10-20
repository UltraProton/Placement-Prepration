#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
class Q_node{
    public:
    int v;
    int dist;
    Q_node(){}
    Q_node(int v,int dist): v(v), dist(dist){}
};

class compare{
    public:
    bool operator()(const Q_node &x, const Q_node &y){
        return x.dist > y.dist;
    }
};

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    priority_queue<Q_node,vector<Q_node>,compare> Q;
    vector<vector<pair<int,int>>> G(n+1);
    vector<int> processed(n+1,0);
    vector<int> dist(n+1,100000);

    for(auto edge : edges){
        G[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
        G[edge[1]].emplace_back(make_pair(edge[0],edge[2]));
    }

    Q_node src(s,0);
    dist[s]=0;
    Q.push(src);

    Q_node curr;


    while(!Q.empty()){
        curr=Q.top();
        cout<<curr.v<<endl;
        dist[curr.v]= curr.dist;
        processed[curr.v]=1;
        Q.pop();

        for(auto u: G[curr.v] ){
            if(dist[u.first]> dist[curr.v] + u.second){
                dist[u.first]= dist[curr.v]+u.second;
                Q.push(Q_node(u.first, dist[u.first]));
            }
        }
    }

    vector<int> ans;

    for(int i=1;i<=n;i++){
        if(i!=s){
            if(dist[i]==100000){
                ans.emplace_back(-1);
            }
            else{
                ans.emplace_back(dist[i]);
            }
        }
    }

    return ans;
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

        vector<int> result = shortestReach(n, edges, s);

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
