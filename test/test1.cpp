#include<bits/stdc++.h>
using namespace std;

struct p{
    int data;
    int *ptr;
    //constructor special function
    p(int val):data(val),ptr(NULL){}  
};

void fun(struct p *var);
int bar(struct p *m, int y);
int main(){
    struct p *var = new struct p(3);
    cout<<var->data<<endl;
    
    fun(var);

    bar(var,5);

    return 0;
}
void fun(struct p *var){
    var->ptr=new int[5];
    for(int i=0;i<5;i++){
        var->ptr[i]=++i;
    }
    //return -1;
}

int bar(struct p *m, int y){
    int *x=m->ptr;
    for(int i=0;i<5;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}