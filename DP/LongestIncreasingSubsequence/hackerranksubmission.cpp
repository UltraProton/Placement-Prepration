/* 
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

 */



#include<bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int> &A);
int first_smallest_element(vector<int> &V, int x, int l, int r);
int first_smallest_element_tweaked(vector<int> &V, int x, int l, int r);
int ceil_index(vector<int> &V, int x, int l, int r);
void print_vec(vector<vector<int>> &V);



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

    cout<<result<<endl;

    fout << result << "\n";

    fout.close();

    return 0;
}
int longestIncreasingSubsequence(vector<int> &A){
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

    //print_vec(active_lists);
    //cout<<largest_len<<endl;

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
