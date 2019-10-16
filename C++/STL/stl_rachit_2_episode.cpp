#include<bits/stdc++.h>

using namespace std;

void show(vector<long long> &);

int main(void){
    int n;

    cin>>n;

    vector<long long > v(n+5,0);

    long long sum= 0;

    for(int i=0; i<n; i++){
        cin>>v[i];
        sum+= v[i];
    }

    unordered_map<long long , int> first, second;

    first[v[0]]= 1;

    for(int i=1;i< n; i++)
        second[v[i]]++;


    //sum= accumulate(v.begin(),v.end(),0);


    //cout << sum << endl;

    if(sum&1)
    {
        cout <<"NO\n";
        return 0;
    }

    //vector<long long> prefix_sum(n+5,0);

    //partial_sum(v.begin(), v.end(), prefix_sum.begin());

    //show(prefix_sum);

    long long sdash=0;

    for(int i =0; i < n ;i++){
        sdash+=v[i];
        if(sdash==sum/2){
            cout<<"YES\n";
            return 0;
        }

        else if(sdash < sum/2){
            long long x= sum/2- sdash;
            if(second[x] > 0){
                cout <<"YES" <<endl;
                return 0;
            }
        }

        else{
            long long y= sdash- sum/2;
            if(first[y] > 0){
                cout <<"YES"<<endl;
                return 0;
            }
        }

    first[v[i+1]]++;
    second[v[i+1]]--;

    }

    cout <<"NO"<<endl;

    return 0;
}


void show(vector<long long> &x){
    for(auto p: x)
        cout<< p<< " ";
    cout << endl;
}
