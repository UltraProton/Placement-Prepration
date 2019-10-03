#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} 

/*This is a function problem.You only need to complete the function given below*/
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/


struct box{
    int h;
    int w;
    int d;
    box(int h, int w, int d): h(h), w(w),d(d){}
};

bool compare(const box &b1, const box &b2){
    return (b1.w*b1.d > b2.w*b2.d);
}

int max_height(vector<box> &boxes);

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<box> boxes;
    int i=0;
    while(i<n){

        //? Find out why this consistency of either of the 2 width and length has to be greater needs to be maintained
        //* consider the width to be always larger than length or depth without loss of generality
        boxes.emplace_back(box(height[i],max(width[i],length[i]),min(width[i], length[i])));//original box
        boxes.emplace_back(box(width[i],max(height[i],length[i]),min(height[i],length[i])));//first rotation
        boxes.emplace_back(box(length[i],max(height[i],width[i]), min(height[i],width[i])));//second rotation
        i++;
    }

    return max_height(boxes);
}


int max_height(vector<box> &boxes){

    int n=boxes.size();

    //* sort all the configurations of boxes in decreasing order of base (width*depth)
    sort(boxes.begin(), boxes.end(), compare);

    // for(auto x:boxes){
    //     cout<<x.w*x.d<<" ";
    // }

    // cout<<endl;

    vector<int> heights(n,0);

    heights[0]=boxes[0].h;

    for(int i=1;i<n;i++){
        heights[i]=boxes[i].h;
        for(int j=0;j<i;j++){
            if(boxes[j].w > boxes[i].w && boxes[j].d > boxes[i].d ){
                if(heights[j]+ boxes[i].h >   heights[i]){
                    heights[i]= heights[j]+ boxes[i].h;
                }
            }
        }
    }

    int ans=INT_MIN;

    for(auto x:heights){
        ans= max(ans, x);
    }

    //cout<<ans<<endl;

    return ans;

}