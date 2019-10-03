/* 

https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

 */

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int id;
    int dist;
    node(){}
    node(int x, int y){
        id=x;
        dist=y;
    }
};

int min_moves(vector<int> &board);

int main() 
{ 
    int t=0;
    int n=0;    
    int a=0,b=0;
    vector<int> board;

    cin>>t;

    while (t>0)
    {
        board.clear();
        board= vector<int>(30,-1);

        cin>>n;
        
        while (n>0)
        {
            cin>>a;
            cin>>b;

            board[a-1]=b-1;

            n--;
            
        }

        cout<<min_moves(board)<<endl;
        
        t--;
    }
      
    return 0; 
} 

int min_moves(vector<int> &board){
    queue<node> Q;
    vector<int> visited(30,0);

    Q.push(node(0,0));

    node curr;
    int curr_id=0;
    int curr_dist=0;
    visited[curr_id]=1;

    while (!Q.empty())
    {
        curr= Q.front();
        curr_id=curr.id;
        curr_dist=curr.dist;

        if(curr_id==29){ //* If the destination vertex is processed in the graph i.e it is removed from the queue meaning we got
                        //* final shortest distance to the destination then we can stop exploring the graph further
            break;
        }

        //visited[curr_id]=1;// ! In BFS we do visited in while traversing the adjacent vertices

        Q.pop();
        //* For each cell reachable from the current node
        for(int i=1;i<=6;i++){
            if(i+curr_id < 30 && !visited[i+curr_id]){
                visited[i+curr_id]=1;
                // * The below commented code is not right because we may reach the destination cell without completely finding 
                //* the shortest path to the destination as there are snakes and ladders in the board
                
                // if(i+curr_id==29){
                //     return curr_dist+1;
                // }

                if(board[i+curr_id]==-1){
                    Q.push(node(i+curr_id,curr_dist+1));
                }

                else{
                    Q.push(node(board[i+curr_id],curr_dist+1));
                }
            }
        }
    }

    //? Very important edge case if we are unable to reach to the 30 th cell then we don't have an answer in which case we will
    //? be given random ans as the break condition in the BFS will not be executed so in the end queue will become empty and the 
    //? ans will be of the last dequeued node which is wrong

    //* To avoid this we should have this check

    if(curr.id!=29){
        return -1;
    }

    return curr.dist;
}