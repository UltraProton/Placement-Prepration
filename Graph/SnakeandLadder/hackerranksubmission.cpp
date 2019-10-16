#include <bits/stdc++.h>
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
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

    vector<int> board(100,-1);

    for(auto x: ladders){
        board[x[0]-1]= x[1]-1;
    }


    for(auto x: snakes){
        board[x[0]-1]= x[1]-1;
    }

    return min_moves(board);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        cout<<result<<endl;

        fout << result << "\n";
    }

    fout.close();

    return 0;
}



int min_moves(vector<int> &board){
    queue<node> Q;
    vector<int> visited(100,0);

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

        if(curr_id==99){ //* If the destination vertex is processed in the graph i.e it is removed from the queue meaning we got
                        //* final shortest distance to the destination then we can stop exploring the graph further
            break;
        }

        //visited[curr_id]=1;// ! In BFS we do visited in while traversing the adjacent vertices

        Q.pop();
        //* For each cell reachable from the current node
        for(int i=1;i<=6;i++){
            if(i+curr_id < 100 && !visited[i+curr_id]){
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

    //cout<<curr.id<<endl;

    if(curr.id!=99){
        return -1;
    }

    return curr.dist;
}