#include<iostream>

using namespace std;

bool rat_maze(int **G, int r, int c, int m, int n, int **solution);
bool issafe(int **G,int r, int c,int m, int n);
void print_solution(int **solution, int r ,int c);

int main(){
	ios::sync_with_stdio(0);

	int r = 0, c=0;
	
	cout << "Enter row count: ";
	cin>>r;
	cout << "Enter col count: ";
	cin>>c;

	int **G = new int*[r];
    int **sol= new int*[r];

	for (int i = 0; i < r; i++){
		G[i] = new int[c];
        sol[i]=new int[c];
	}

    memset(G,0,sizeof(G));
    memset(sol,0,sizeof(G));

    if(rat_maze(G,0,0,r,c,sol)){
        print_solution(sol,r,c);
    }

	return 0;
}

bool rat_maze(int **G, int r, int c, int m, int n,int **solution){
    //If we have reached the destination
    if(r==m-1 && c==n-1){
        ///Include the last cell as part of the solution
        solution[r][c]=1;
        return true;
    }

    //If it's safe to include current cell in the solution
    if(issafe(G,r+1,c,m,n,solution){
        //Include the current cell in the solution
        solution[r][c]=1;

        //explore the right direction from current cell
        if(rat_maze(G,r,c+1,m,n,solution)){
            return true;
        }

        //explore the down direction from current cell
        if(rat_maze(G,r+1,c,m,n,solution)){
            return true;
        }

        //revert back the cell value to 0 as this cell didn't finally lead to solution
        solution[r][c]=0;

        return false;
    }

    return false;
}

void print_solution(int **sol,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<sol[r][c]<<" ";
        }
        cout<<endl;
    }
}