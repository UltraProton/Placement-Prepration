#include<bits/stdc++.h>

using namespace std;

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

int main(int argc, char const *argv[])
{

    box b1(1,2,3);

    box b2(3,4,5);

    vector<int> input;

    vector<box> boxes;
    // boxes.emplace_back(b1);
    // boxes.emplace_back(b2);
    int t=0, n=0, x=0;
    int h=0,w=0,d=0;

    cin>>t;
    while(t>0){
        boxes.clear();
        cin>>n;
        while(n>0){
            cin>>h>>w>>d;
            boxes.emplace_back(box(h,w,d));
            boxes.emplace_back(box(w,h,d));
            boxes.emplace_back(box(d,h,w));
            n--;
        }

        cout<<max_height(boxes)<<endl;

        t--;
    }

    
    return 0;
}


int max_height(vector<box> &boxes){

    int n=boxes.size();

    //* sort all the configurations of boxes in decreasing order of base (width*depth)
    sort(boxes.begin(), boxes.end(), compare);

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

