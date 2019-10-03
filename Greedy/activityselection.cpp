#include<bits/stdc++.h>

using namespace std;

int activities(vector<pair<int,int>> &activity);
bool compare(pair<int,int> & p, pair<int,int> &q);

int main(){
    
    int t=0,n=0,s=0,f=0,x=0;
    vector<pair<int, int>> activity;

    vector<int> starting;
    vector<int> finishing;

    cin>>t;
    
    while(t>0){
        cin>>n;
        x=n;
        while(x>0){
            cin>>s;
            starting.push_back(s);
            x--;
        }

        x=n;
        while(x>0){
            cin>>f;
            finishing.push_back(f);
            x--;
        }

        for(int i=0;i<starting.size();i++){
            activity.push_back(make_pair(starting[i], finishing[i]));
        }

        std::sort(activity.begin(), activity.end(), compare);

        cout<<activities(activity)<<endl;

        activity.clear();

        starting.clear();
        finishing.clear();

        t--;
    }



    return 0;
}


int activities(vector<pair<int, int>> &V){
    //std::sort(V.begin(), V.end(), compare);
    int count=1;
    
    pair<int,int> prev=*(V.begin());
    
    //cout<<prev.second<<endl;

    pair<int,int> curr;
    for(int i=1;i<V.size();i++){
        curr= V[i];
        if(prev.second<=curr.first){
            count++;
            prev=curr; // we select the current activity and change prev to curr to see if further activities 
                      //can be selected or not
        }
    }
    
    return count;
}

bool compare(pair<int,int> &p, pair<int,int> &q){
    return (p.second < q.second);
}

