#include<bits/stdc++.h>

using namespace std;

/* This is the first implementation*/
int XorFirst(int a, int b){
    return ((a|b) - (a&b));
}
/*Implement with the help of traversing the bits*/
int XorSecond(int a, int b){
    int ans=0;
    /*Assumming the two numbers are represented in 32 bits*/
    for(int i=0;i<=31;i++){
        if(((1<<i)&a) != ((1<<i)&b)){
            ans= (ans|(1<<i));        
        }
    }
    
    return ans;
}

int XorThird(int x, int y) 
{ 
    int res = 0; // Initialize result 
      
    // Assuming 32-bit Integer  
    for (int i = 31; i >= 0; i--)                      
    { 
       // Find current bits in x and y 
       bool b1 = x & (1 << i); 
       bool b2 = y & (1 << i); 
         
        // If both are 1 then 0 else xor is same as OR 
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);           
  
        // Update result 
        res <<= 1; 
        res |= xoredBit; 
    } 
    return res; 
} 

int XorFourth(int a, int b){
    return ((a|b) & (~a|~b));
}

int XorFinal(int a, int b){
    return ((a&~b) | (~a&b));
}


int main(){
    int a=0,b=0;
    cin>>a>>b;
    cout<<XorFirst(a,b)<<" "<<(a^b)<<endl;
    cout<<XorSecond(a,b)<<" "<<(a^b)<<endl;
    cout<<XorThird(a,b)<<" "<<(a^b)<<endl;    
    cout<<XorFourth(a,b)<<" "<<(a^b)<<endl;    
    cout<<XorFinal(a,b)<<" "<<(a^b)<<endl;    
    return 0;
}
