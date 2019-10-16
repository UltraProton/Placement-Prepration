/* 
https://practice.geeksforgeeks.org/problems/find-the-distance-between-two-nodes/0/?ref=self


! Pending.


 */

#include<bits/stdc++.h>

using namespace std;

int shortest_dist(int x, int y);

int main(int argc, char const *argv[])
{
    /* code */
    int t=0;
    int x=0;
    int y=0;

    cin>>t;
    while (t>0)
    {
        cin>>x;
        cin>>y;

        cout<<shortest_dist(x,y);
        t--;
    }
    
    return 0;
}


int shortest_dist(int x, int y){
    //cout<<x<<" , "<<y<<endl;
    //return abs((ceil(sqrt(y))- ceil(sqrt(x))));//! Incorrect: To find the correct level of node you must do log2(x)


}