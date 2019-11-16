#include<bits/stdc++.h>

using namespace std;

void fun1(long double);
void fun2(long double);

int main(){
    long double x=0;
    cin>>x;
    //fun2(x);
    fun1(x);
    cout<<endl;
    return 0;
}

void fun1(long double x){
    float in=1.46473459586;
    int mant= int(in);
    int ex= (float)(in-mant)*1000000;
   
    float n=ex;
    
    cout<<n<<endl;

    n=n/10;

    cout<<n<<endl;
    
    n=roundf(n);

    cout<<n<<endl;
    
    n=(float)mant*100000+n;

    cout<<n<<endl;
    
    cout<<n/100000;
}

void fun2(long double x){
    long long m= int(x);
    long long e= double(x-m)*10000000;

    cout<<e<<endl;

    long double t=e;

    t=t/10;

    printf("%ld",t);

    t= roundf(t);

    long double ans= double(m)*1000000+t;

    ans=ans/1000000;

    cout<<ans<<endl;

}