/* 

 */

#include<bits/stdc++.h>

using namespace std;

void sort_functionality(vector<int> &V);

int main(int argc, char const *argv[])
{   
    //* By default we have max heap in stl priority queue
    priority_queue<int> max_heap;
    //* Here we need to have 2 extra parameters called to make it min heap. 
    //* Note: Give attention to how greater<int> is passed as argument in priority queue
    //? Don't be confused on how greater is passed as argument in sort see sort_functionality()
    //! It is passed as greater<int>() in sort
    priority_queue<int, vector<int> , greater<int>> min_heap; //* We can say because here we are declaring so no point of greater<int>()
                                                            //* which will make it funtion call

    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(-1);
    max_heap.push(5);

    cout<<"max heap: "<<endl;

    // lets see what the max heap looks like
    while (!max_heap.empty())
    {
        cout<<max_heap.top()<<endl;
        max_heap.pop();
    }

    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(-1);
    min_heap.push(5);

    cout<<"min heap: "<<endl;

    while (!min_heap.empty())
    {
        cout<<min_heap.top()<<endl;
        min_heap.pop();
    }

    vector<int> V{1,2,3,4,5,6};

    sort_functionality(V);

    return 0;
}

void sort_functionality(vector<int> &V){
    //sorting in descending order
    sort(V.begin(), V.end(), greater<int>()); //* Its a function call of greater<int>() here.

    for(auto x:V){
        cout<<x<<" ";
    }

}
