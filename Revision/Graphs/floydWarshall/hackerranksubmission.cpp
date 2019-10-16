#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void floyd_warshall(vector<vector<int>> &G,vector<vector<int>> &Q, int n){
    
    vector<vector<int>> dist(n+1,vector<int>(n+1,100000));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]= G[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(dist[u][v]> dist[u][k]+ dist[k][v]){
                    dist[u][v]= dist[u][k]+ dist[k][v];
                }
            }
        }
    }

    for(auto q: Q){
        if(dist[q[0]][q[1]]==100000){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[q[0]][q[1]]<<endl;    
        }
    }
}

int main()
{
    int road_nodes;
    int road_edges;

    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cout<<road_edges<<endl;

    
    vector<vector<int>> G(road_nodes+1,vector<int>(road_nodes+1,100000));

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);

    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //cout<<'x'<<endl;

    int q;
    cin >> q;

    vector<vector<int>> Q(q);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);
        int y = stoi(xy[1]);        
        
        Q[q_itr].emplace_back(x);
        Q[q_itr].emplace_back(y);
    }

    // for(auto q:Q){
    //     cout<<q[0]<<","<<q[1]<<endl;
    // }

    
    for(int i=0;i<road_edges;i++){
        G[road_from[i]][road_to[i]]=road_weight[i];
    }

    
    // for(int i=0;i<road_edges;i++){
    //     cout<<i<<endl;
    //     cout<<G[road_from[i]][road_to[i]]<<endl;
    // }

    //cout<<G.size()<<endl;


    // for(auto vec: G){
    //     for(auto ele: vec){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    floyd_warshall(G,Q,road_nodes);

    G.clear();

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
