#include<bits/stdc++.h>

using namespace std;

// complexity= O(n^2)
long long rain_Water_1(vector<long long> &v){
    long long l=0,r=0,ans=0;
    for(int i=1;i < v.size()-1; i++){
        l= *(std::max_element(v.begin(), v.begin()+i));
        r= *(std:: max_element(v.begin()+i+1, v.end()));
        long long Min= std::min(l,r);

        if(Min > v[i])
            ans+= (Min- v[i]);
    }

    return ans;
}

// efficient solution: compute and store the left max and right max for each element in the array

long long rain_Water_2(vector<long long> &v){
    long long n= v.size();
    long long ans=0;
    vector<long long> l_max(n);
    vector<long long> r_max(n);

    l_max[0]= v[0];
    for(int i=1;i< n; i++)
        l_max[i]= max(l_max[i-1],v[i]);

    r_max[n-1]= v[n-1];
    for(int i=n-2; i>=0; i--)
        r_max[i]= max(r_max[i+1],v[i]);

    for(int i=0; i< n; i++)
        ans+= min(l_max[i], r_max[i])- v[i];

    return ans;
}



int main(void){
    vector<long long> v;
    v.push_back(6);
    v.push_back(9);
    v.push_back(9);
    //v.push_back(5);
    //v.push_back(0);
    //v.push_back(3);
    //v.push_back(0);
    //v.push_back(1);

    cout << rain_Water_1(v) << endl;
    cout << rain_Water_2(v) << endl;

    //cout << *(v.begin()+2)<< endl;

    return 0;
}

