#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll edit_dist(string &s1, string &s2, int m, int n,vector<vector<ll>> &memo);
void print_memo(vector<vector<ll>> &memo);


int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<ll>> memo(10,vector<ll>(10,-1));
    string s1="abcdef";
    string s2="acf";

    cout<<edit_dist(s1,s2,s1.size(),s2.size(),memo)<<endl;

    print_memo(memo);

    return 0;
}

ll edit_dist(string &s1, string &s2, int m, int n, vector<vector<ll>> &memo){
    /* If we already have the ans then just return */
    if(memo[m][n]!=-1){
        return memo[m][n];
    }

    //if the first string is empty then we need edits equal to the size of the second string and vice-versa.
    if(m==0){
        memo[m][n]=n;
        return n;
    }

    if(n==0){
        memo[m][n]=m;
        return m;
    }

    //if the characters at the last positions match then find the answer with the remaining substring
    if(s1[m-1]==s2[n-1]){
        memo[m][n]= edit_dist(s1,s2,m-1,n-1,memo);
        return memo[m][n];
    }

    else{
        /* insert the character which is present in 2nd string into the current position in first string. First string
        is changed in this and we have handled the character mismatch in first string with second string. Now we should
        move ahead in second string  */
        ll insert_ans = edit_dist(s1,s2,m,n-1,memo); 
        /* Remove the mismatched character in the first string and move ahead we accounted the mismatch by removing the
        character in the first string but we don't move ahead in the second string  */
        ll remove_ans= edit_dist(s1,s2,m-1,n,memo);
        /*
        Handle mismatch by replacing the current characters from both the strings to a common character 
         */
        ll replace_ans= edit_dist(s1,s2,m-1,n-1,memo);
        
        //find the min of the three operations    
        memo[m][n]=   1 + min(remove_ans, min(insert_ans, replace_ans));

        return memo[m][n];
    }
}


void print_memo(vector<vector<ll>> &memo){
    for(auto vec:memo){
        for(auto ele:vec){
            cout<<ele<<"    ";
        }
        cout<<endl;
    }
}