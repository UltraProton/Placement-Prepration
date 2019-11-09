#include <bits/stdc++.h> 

using namespace std;

bool solveMazeUtil(int **maze, int x, int y, int **sol,int N); 

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int **sol,int N) 
{ 
    cout<<endl;
    cout<<"Solution path: "<<endl;

	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++){ 
			    if(sol[i][j]==1){
                    cout<<"["<<i<<","<<j<<"],";
                }
	    } 
    }
} 

/* A utility function to check if x, y is valid index for N*N maze */
bool isSafe(int **maze, int x, int y, int N) 
{ 
	// if (x, y outside maze) return false 
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
		return true; 

	return false; 
} 

/* This function solves the Maze problem using Backtracking. It mainly 
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the 
form of 1s. Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/
bool solveMaze(int **maze, int N) 
{ 
	int **sol=new int*[N];
    for(int i = 0; i < N; ++i){
        sol[i] = new int[N];
    }
         
	if (solveMazeUtil(maze, 0, 0, sol,N) == false) { 
		printf("[No solution Available]"); 
		return false; 
	} 

	printSolution(sol,N);

	return true; 
} 

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int **maze, int x, int y, int **sol,int N) 
{ 
	// if (x, y is goal) return true 
	if (x == N - 1 && y == N - 1) { 
		sol[x][y] = 1; 
		return true; 
	} 

	// Check if maze[x][y] is valid 
	if (isSafe(maze, x, y,N) == true) { 
		// mark x, y as part of solution path 
		sol[x][y] = 1; 

		/* Move forward in x direction */
		if (solveMazeUtil(maze, x + 1, y, sol,N) == true) 
			return true; 

		/* If moving in x direction doesn't give solution then 
		Move down in y direction */
		if (solveMazeUtil(maze, x, y + 1, sol,N) == true) 
			return true; 
        
        //Move left to find the solution
        if (solveMazeUtil(maze, x, y - 1, sol,N) == true) 
			return true; 
        
        //Move right to find the solution
        if (solveMazeUtil(maze, x-1, y , sol,N) == true) 
			return true; 

		/* If none of the above movements work then BACKTRACK: 
			unmark x, y as part of solution path */
		sol[x][y] = 0; 
		return false; 
	} 

	return false; 
} 

// driver program to test above function 
int main() 
{ 

    //Taking the input as long as a correct input is not given by the user
    while(1){
        string input="";
        getline(cin,input);

        long double sr = sqrt(input.size()); 

        // If square root is not an integer we need another input from the user
        if((sr - floor(sr)) != 0){
            cout<<"The input grid is not symmetric. Please enter valid input."<<endl;
            continue;
        } 

        else{

            //Create the grid
            int n= sr;
            int **maze=new int*[n];
            for(int i = 0; i < n; ++i){
                maze[i] = new int[n];
            }

            //Fill the grid with the input
            int k=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    //Filling the values in the grid
                    maze[i][j]=input[k]-'0';
                    k++;
                }
            }
            
            //We need to solve the maze as it is a valid input
            solveMaze(maze,n);
            //As soon as we get the output we will break
            break;
        }
    }

	return 0; 
} 
