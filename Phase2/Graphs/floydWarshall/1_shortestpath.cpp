#include<bits/stdc++.h>

using namespace std;

class edge{
    public:
    string src;
    string dest;
    int price;
    edge(){}
    edge(string src, string dest, int price): src(src), dest(dest), price(price){}
};


void cheapest_flight(vector<edge> &flights, string src, string dest, int k);
void print_path(unordered_map<string,string> &mp, string curr);
void cheapest_flight2(vector<vector<int>> &G, string &src, string &dest, unordered_map<string, int> &mp,int p);

int main(int argc, char const *argv[])
{
    /* code */

    unordered_map<string, int> mp;

    mp["madrid"]=0;
    mp["rome"]=1;
    mp["munich"]=2;



    vector<vector<int>> G(3,vector<int>(3,10000));
    
    G[mp["madrid"]][mp["rome"]]=300;
    G[mp["rome"]][mp["munich"]]=150;
    G[mp["munich"]][mp["madrid"]]=200;
    G[mp["munich"]][mp["rome"]]=600;

    // for(auto vec: G){
    //     for(auto ele: vec){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }


    // edge e1("madrid", "rome",300);
    // edge e2("rome", "munich",150);
    // edge e3("munich", "madrid",200);
    // edge e4("munich", "rome",600);

    // vector<edge> flights{e1,e2,e3,e4};

    string src="";
    string dest="";
    int p=0;

    // cin>>src>>dest>>k;

    cin>>src>>dest>>p;

    // cheapest_flight(flights,src,dest, k);


    cheapest_flight2(G,src,dest,mp,p);

    return 0;
}

void cheapest_flight2(vector<vector<int>> &G, string &src, string &dest, unordered_map<string, int> &mp,int p){
    vector<vector<int>> dist=G;
    int n=G.size();

    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }

    for(int k=0;k<p;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j]= dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(auto vec: dist){
        for(auto ele: vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }



    cout<<dist[mp[src]][mp[dest]]<<endl;
}


void cheapest_flight(vector<edge> &flights, string src, string dest, int k){
    unordered_map<string,vector<edge>> mp1;
    unordered_map<string,int> mp2;
    unordered_map<string,string> mp3;

    set<string> cities;

    for(auto x: flights){
        cities.insert(x.src);
        cities.insert(x.dest);
    }

    // for(auto x:cities){
    //     cout<<x<<endl;
    // }
    
    for(auto city: cities){
        mp2[city]=1000;
        mp3[city]="0";
    }

    for(auto x: flights){
        mp1[x.src].emplace_back(x);
    }

    // for(auto x: mp1){
    //     cout<<x.first<<": ";
    //     for(auto node: x.second){
    //         cout<<"("<<node.dest<<","<<node.price<<"),";
    //     }

    //     cout<<endl;
    // }

    int V= mp1.size();

    // cout<<V<<endl;

    int i=0;

    //initialize single source

    mp2[src]=0;

    // for(auto x: mp2){
    //     cout<<x.first<<","<<x.second<<endl;
    // }
    
    while(i<k){
        for(auto x:flights){
            if(mp2[x.dest]> mp2[x.src] + x.price){
                mp3[x.dest]= x.src;
                mp2[x.dest]= mp2[x.src]+ x.price;
            }
        }
        i++;
    }

    //cout<<mp2["madrid"]<<endl;

    //print path

    // for(auto x: mp3){
    //     cout<<x.first<<","<<x.second<<endl;
    // }

    stack<string> st;

    string curr=dest;

    while (curr!="0")
    {   
        cout<<curr<<endl;
        st.push(curr);
        curr=mp3[curr];
    }

    if(st.size() > k){
        cout<<"Error"<<endl;
    }

    else{
        cout<<mp2[dest]<<endl;
        while (!st.empty())
        {
            curr=st.top();
            cout<<curr<<" ";
            st.pop();
        }
    }

    cout<<endl;
}

