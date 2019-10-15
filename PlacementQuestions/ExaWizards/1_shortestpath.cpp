#include<bits/stdc++.h>

using namespace std;

class edge{
    public:
    string src;//source of the graph
    string dest;
    int price;
    edge(){}
    edge(string src, string dest, int price): src(src), dest(dest), price(price){}
};


void cheapest_flight(vector<edge> &flights, string src, string dest, int k);
void print_path(unordered_map<string,string> &mp, string curr);

int main(int argc, char const *argv[])
{
    /* code */

    int n=0;
    int k=0;
    string src="";
    //cout<<endl;
    string dest="";
    //cout<<endl;
    cin>>src;
    cout<<endl;
    cin>>dest;
    cout<<endl;
    cin>>k;
    cout<<endl;
    cin>>n;
    cout<<endl;

    vector<string> curr;

    vector<edge> flights;

    string E="";
    string delimeter=",";

    int i=0;
    int pos=0;

    while(i<n){
        cin>>E;
        cout<<endl;
        curr.clear();
        
        pos=E.find(delimeter);
        while (pos!=string::npos)
        {
            curr.emplace_back(E.substr(0,pos));
            E.erase(0,pos+delimeter.size());
            pos= E.find(delimeter);
        }

        curr.emplace_back(E);

        //so the curr has all the 3 values source destination and fare between them as string so make an edge from this 
        flights.emplace_back(edge(curr[0],curr[1], stoi(curr[2])));
    
        cout<<endl;
        
        i++;
    }

    // for(auto x:flights){
    //     cout<<x.src<<","<<x.dest<<","<<x.price<<endl;
    // }
    
    cheapest_flight(flights,src,dest, k);

    return 0;
}

void cheapest_flight(vector<edge> &flights, string src, string dest, int k){
    unordered_map<string,int> mp1;//to store the final fare of a city
    unordered_map<string,string> mp2;//to store the parent information

    set<string> cities;

    //get all the distinct cities
    for(auto x: flights){
        cities.insert(x.src);
        cities.insert(x.dest);
    }

    // for(auto x:cities){
    //     cout<<x<<endl;
    // }
    
    //initilize single sourc
    for(auto city: cities){
        mp1[city]=10000;
        mp2[city]="0";
    }

    mp1[src]=0;

    int V= cities.size();
    
    int i=0;   

    //The main logic: Bellmann ford gives the shortest between source and destination with no of vertices on the simple path 
    // the source and destination equals the no of time all the edges are relaxed
    // So here we will be relaxing all the edges 'k' times so we will have only k vertices on the simple path from source to
    //destination which in our case also means we will have atmost 'k' tickets using which we can cover atmost 'k' cities in our
    //shortest path from source to destination
    while(i<k){
        for(auto x:flights){
            if(mp1[x.dest]> mp1[x.src] + x.price){
                mp2[x.dest]= x.src;
                mp1[x.dest]= mp1[x.src]+ x.price;
            }
        }
        i++;
    }


    // //print path
    // for(auto x: mp1){
    //     cout<<x.first<<","<<x.second<<endl;
    // }


    //find the shortest path between source and destination
    
    stack<string> st; //stores the no of cities between source and destination excluding source
    string curr=dest;

    //start from the destination and keep moving towards source
    while (curr!=src)
    {   
        st.push(curr);
        curr=mp2[curr];
    }

    //If the no of cities in the shortest path from source to destination are greater than the tickets we have then we can't really
    // have a shortest path
    if(st.size() > k){
        cout<<"Error"<<endl;
        return;
    }

    //print the final fare
    cout<<mp1[dest]<<endl;
    
    //print the path
    st.push(src);
    
    while (!st.empty())
    {
        curr=st.top();
        cout<<curr<<" ";
        st.pop();
    }

    cout<<endl;
}

