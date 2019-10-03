/*

This problem will help you learn concepts involving double and float variables.


 */


#include<bits/stdc++.h>

using namespace std;

/* For precise function we want the ans to be of certain precision */
double my_sqrt_precise(int x);

/* Here we just care about the integral part */
int my_sqrt_integral(int x);


int main(int argc, char const *argv[])
{
    int x=0;
    cin>>x;

    cout<<endl;
    
    cout<<my_sqrt_precise(x)<<endl;
    //cout<<my_sqrt_integral(x)<<endl;

    return 0;
}

double my_sqrt_precise(int x){
    long double l =0;
    long double r= x;
    long double mid=0;
    long double ans=0;

    /* You can set the precision as much as you want. */
    while(r-l>0.001){
        cout<<"l= "<<l<<" mid= "<<mid<<" r = "<<r<<"             mid*mid "<<mid*mid<<" "<<endl;

        mid= l+ (r-l)/2;

        if(mid*mid<=x){
            ans= mid;
            l=mid;
        }

        else{
            r=mid;
        }
    }
    
    cout<<ans<<endl;
    //return l+ (r-l)/2 ;
    return ans;
}


int my_sqrt_integral(int x){
    int l=0;
    int r=x;
    int mid=0;
    
    int ans=0; /* Our final ans */

    while(l<=r){
        //cout<<"l= "<<l<<" mid= "<<mid<<" r = "<<r<<endl;
        mid= l+ (r-l)/2;
        if(mid*mid==x){
            return mid;
        }

        /* We should save the current mid because it can be a potential ans */
        else if(mid*mid <= x){
            ans=mid;
            l=mid+1;
        }
        /* We didn't save ans here because mid > sqrt(x) */
        else{
            r=mid-1;
        }
    }

    return ans;
}