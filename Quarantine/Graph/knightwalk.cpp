#include<bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>,int> ppi;

int knight_walk(int m, int n,pair<int,int> &src, pair<int,int> &dest);
bool is_safe(int x, int y, int m, int n);

int main(){
    int t=0,m=0,n=0;
    int s_x=0,s_y=0,d_x=0,d_y=0;
    int ans=0;
    cin>>t;
    while (t>0)
    {
        cin>>m>>n;
        cin>>s_x>>s_y>>d_x>>d_y;
        pair<int,int> src(s_x,s_y);
        pair<int,int> dest(d_x,d_y);
        ans=knight_walk(m,n,src,dest);
        cout<<ans<<endl;
        t--;
    }
    
    return 0;
}

int knight_walk(int m, int n, pair<int,int> &src, pair<int,int> &dest){
    queue<ppi> Q;
    vector<int> R{-1,-2,-2,-1,1,2,2,1};
    vector<int> C{2,1,-1,-2,-2,-1,1,2};

    vector<vector<int>> visited(m+1,vector<int>(n+1,0));
    ppi curr;
    int x=src.first;
    int y=src.second;
    int s=0;

    Q.push(make_pair(make_pair(x,y),s));
    visited[x][y]=1;

    int p=0;
    int q=0;

    while(!Q.empty()){
        curr= Q.front();
        x=curr.first.first;
        y=curr.first.second;
        s=curr.second;
        Q.pop();

        if(x==dest.first && y==dest.second){
            return s;
        }

        for(int i=0;i<8;i++){
            p=x+R[i];
            q=y+C[i];
            if(is_safe(p,q,m,n) && !visited[p][q]){
                visited[p][q]=1;
                Q.push(make_pair(make_pair(p,q),s+1));
            }
        }
    }

    return -1;
}

bool is_safe(int x, int y, int m ,int n){
    if(x<=0 || x>m || y<=0 || y>n){
        return false;
    }
    else{
        return true;
    }
}