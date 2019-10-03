/* 

* Find whether we have a cycle in the graph formed by the strings.

 */


#include<bits/stdc++.h>

using namespace std;

bool circle_possible(vector<string> &V);
bool find_cycle(vector<vector<int>> &G, vector<int> &color, int src);

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> V;
    int t=0;
    int n=0;
    string x;
    cin>>t;
    while(t>0){
        V.clear();
        cin>>n;
        while(n>0){
            cin>>x;
            V.emplace_back(x);
            n--;
        }

        cout<<circle_possible(V)<<endl;

        t--;
    }
    return 0;
}

bool circle_possible(vector<string> &V){
    int n=V.size();

    if(n==1 && V[0].size()==1){
        return 1;
    }

    else if(n==1 && V[0].size()>1){
        return 0;
    }

    vector<int> color(n,'w');

    vector<vector<int>> G(n);//* Creating a graph

    for(int i=0;i<n;i++){
        for(int j=0;j<n ;j++){
            if(j!=i){
                if(*(V[i].end()-1)==*(V[j].begin())){
                    G[i].emplace_back(j);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        for(auto ele: G[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }


    return find_cycle(G,color,0);
}

bool find_cycle(vector<vector<int>> &G, vector<int> &color, int src){
    color[src]='g';

    for(auto v: G[src]){
        if(color[v]=='b'){
            continue;
        }

        if(color[v]=='g'){
            return true;
        }

        if(find_cycle(G,color,v)){
                return true;
        }
    }

    color[src]='b';

    return false;
}
