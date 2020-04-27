#include<bits/stdc++.h>

int fun1(vector<int> &arr);
pair<in,int> fun2(vector<int> &arr);

int main(){

}

int fun1(vector<int> &arr){
    int meh=0;
    int msf=INT_MIN;
    //At any index what I can do best either I can extend the previous maxsum by including the current element
    //or the current element itself is the best till now. Best of these 2 will be the ans of the array till
    //present index
    for(int i=0;i<arr.size();i++){
        meh=max(arr[i],arr[i]+meh);
        msf=max(meh,msf);
    }
    return msf;
}

//We also want to store the indices of the subarray. This approach is little different here the Kadane's 
//intuitive approach is discussed. In this algorithm all the positive subarray sums are considered and max 
//among them is chosen.
pair<int,int> fun2(vector<int> &arr){
    int s=0;
    int e=0;
    int start=0;
    int meh=0;
    int msf=INT_MIN;
    
    for(int i=0;i<arr.size();i++){
        meh=meh+arr[i];
        //If the sum ending at current index is greater than the best we had
        if(msf < meh){
            msf=meh; //Update the new ans
            start=s; //store the start index of the subarray
            end=i; //Since we have found a new max subarray at current index so this will be the probable end
            //index of the ans
        }

        //If the subarray ending at current index is negative then 
        if(meh<0){
            meh=0; //Update the meh to 0 to be useful for the upcoming subarrays remember we are just considering
            //the positive sums
            s=i+1; //Important: Store the next index because in future we may end up having the upcoming subarray
            //as the answer in which case we need the first index of that array. We are storing it in the hope
            //that we may find the subarray starting at index i+1 having the max subarray sum. I think of this
            //as a greedy step in this algorithm.
        }
    }

    pair<int,int> ans{start,e};

    return ans;
}