#include<bits/stdc++.h>

using namespace std;

void showVector(vector<int> &);

int isOdd(int x){
    return x%2==1;
}

int main(void){
    /*
    vector<int> v{9,5,4,3,2,1,0,-90};
    cout <<"vector 1: "<< endl;
    showVector(v);

    partition(v.begin(), v.end(), isOdd);

    showVector(v);

    // Geeks article way of partition
    vector<int> v1{1,4,5,6,7,8,90,23,67};
    cout<< "vector 2:"<< endl;
    showVector(v1);

    partition(v1.begin(),v1.end(), [](int x)
              {
              return x%2==1;
              }
              );

    showVector(v1);

    // checking whether the container is partitioned according to a condition
    bool v_partitioned= is_partitioned(v.begin(), v.end(), isOdd);
    bool v1_partitioned= is_partitioned(v1.begin(),v1.end(), [] (int x){
                                        return x%2==0;
                                        }
                                        );
    cout << "v partioned?: " << v_partitioned <<"\nv1 partitioned?: " << v1_partitioned << endl;

    // stable_partition() is used to maintain the relative order of the elements in the container while partitioning the
    // container

    */

    vector<int> v2{9,4,5,6,6,23,4,5,6,7,8,90};

    stable_partition(v2.begin(), v2.end(), isOdd);
    showVector(v2);

    // partition_point() returns an iterator to the first element in the container which doesn't satisfy the condition
    // Remember: container needs to be partitioned before applying this function.

    auto it= partition_point(v2.begin(), v2.end(), isOdd);

    cout << "partition point element: " << *it << endl;

    // partition_copy() is used to copy the 2 partitions to two different containers
    int true_count= it- v2.begin();

    //cout << true_count <<endl;


    vector<int> true_elements(true_count);
    vector<int> false_elements(v2.size()-true_count);

    partition_copy(v2.begin(), v2.end(), true_elements.begin(), false_elements.begin(), isOdd);

    cout << "Elements satisfying the condition:" << endl;
    showVector(true_elements);

    cout << "Elements not satisfying the condition: " << endl;
    showVector(false_elements);

    return 0;
}


void showVector(vector<int> &v){
    for(auto x: v)
        cout << x << " ";
    cout<<endl;
}

