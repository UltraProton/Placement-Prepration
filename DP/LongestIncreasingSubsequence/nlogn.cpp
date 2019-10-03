/* 
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

 */



#include<bits/stdc++.h>

using namespace std;

int longest_inc_subseq(vector<int> &A);
int first_smallest_element(vector<int> &V, int x, int l, int r);
int first_smallest_element_tweaked(vector<int> &V, int x, int l, int r);
int ceil_index(vector<int> &V, int x, int l, int r);
void print_vec(vector<vector<int>> &V);

int main(int argc, char const *argv[])
{
    vector<int> V;
    int n=0;
    int x=0;
    int t=0;

    //vector<int> test_vec{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };

    //vector<int> test_vec{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    vector<int> test_vec{1,2,3,4,5,5};



    //cout<<first_smallest_element(test_vec,3,0,test_vec.size()-1)<<endl;
    cout<<ceil_index(test_vec,5,0,test_vec.size()-1)<<endl;
    cout<<first_smallest_element_tweaked(test_vec,5,0,test_vec.size()-1)<<endl;
    

    //cout<<longest_inc_subseq(test_vec)<<endl;

    // cin>>t;

    // while(t>0){
    //     V.clear();
    //     cin>>n;
    //     while(n>0){
    //         cin>>x;
    //         V.emplace_back(x);
    //         n--;
    //     }

    //     cout<<longest_inc_subseq(V)<<endl;
        
    //     t--;
    // }

    return 0;
}

int longest_inc_subseq(vector<int> &A){
    int largest_len=0;
    vector<vector<int>> active_lists(A.size()+5);
    vector<int> last_elements(A.size()+5,-1);

    //insert the first element into the active lists. The first element will make a active list of length 1
    active_lists[1]=(vector<int>{A[0]});
    last_elements[1]=A[0];

    largest_len++;

    for(int i=1;i<A.size();i++){
        if(A[i] < last_elements[1]){
            active_lists[1]= vector<int>{A[1]};
            last_elements[1]=A[i];
        }

        else if(A[i] > last_elements[largest_len] ){
            // * we can copy a vector to new vector using "=" assingnment operator
            vector<int> new_vector= active_lists[largest_len];
            new_vector.push_back(A[i]);
            largest_len++;
            active_lists[largest_len]=new_vector;
            last_elements[largest_len]=A[i];
        }

        else{
            //find the largest active list whose last element is smaller than the current element
            int k=0;
            // for(k=largest_len;k>=1;--k){
            //     if(last_elements[k]<A[i]){
            //         break;
            //     }
            // }

            k=first_smallest_element(last_elements,A[i],1,largest_len);

            //cout<<'x'<<endl;

            vector<int> new_vector= active_lists[k];
            new_vector.push_back(A[i]);
            k+=1;
            active_lists[k]= new_vector;
            last_elements[k]=A[i];
        }        
    }

    print_vec(active_lists);

    return largest_len;
}


int first_smallest_element(vector<int> &last_elements, int element, int l, int r){
    int mid=-1;
    int ans=-1;
    while(l<r){
        mid= l + (r-l)/2;

        if(last_elements[mid] < element ){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid;
        }

        //cout<<l<<" , "<<mid<<" , "<<r<<endl;
    }

    return ans; 
}


void print_vec(vector<vector<int>> &V){
    for(auto x:V){
        for(auto ele:x){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int ceil_index(vector<int> &V, int key, int l, int r){
    int mid=-1;
    while(r-l>1){
        mid=l + (r-l)/2;
        if(V[mid] <= key){
            l=mid;
        }
        else{
            r=mid;
        }
    }
}

int first_smallest_element_tweaked(vector<int> &last_elements, int element, int l, int r){
    int mid=-1;
    int ans=-1;
    while(r-l>1){
        mid= l + (r-l)/2;

        if(last_elements[mid] < element ){
            ans=mid;
            l=mid;
        }
        else{
            r=mid;
        }

        cout<<l<<" , "<<mid<<" , "<<r<<endl;
    }

    return ans; 
}
