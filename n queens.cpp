#include<stdio.h>
#include<stdbool.h>
#define N 8
//Function to print the final placement of queens on the board
void printSolution(int board[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c ",board[i][j]?'Q':'-');
        }
        printf("\n");
    }
}
//Function to check if it's safe to place a queen at a given position
bool isSafe(int board[N][N],int row,int col){
    //Check if there is a queen in the same row
    for(int i=0;i<col;i++){
        if(board[row][i]) {
            return false;
        }
    }
    //Check if there is a queen in the upper diagonal
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    //Check if there is a queen in the lower diagonal
    for(int i=row,j=col;i<N&&j>=0;i++,j--){
        if (board[i][j]){
            return false;
        }
    }
    //If no queen is threatening, it's safe to place a queen at this position
    return true;
}
//Recursive backtracking function to solve the N-Queens problem
bool solveNQueensUtil(int board[N][N],int col){
    //If all queens are placed, return true
    if(col==N){
        return true;
    }
    //Try placing a queen in each row of the current column
    for(int i=0;i<N;i++){
        if(isSafe(board,i,col)){
            //Place the queen and recursively try to place the rest of the queens
            board[i][col]=1;
            if(solveNQueensUtil(board,col+1)){
                return true; //Solution found
            }
            //If placing queen in the current position doesn't lead to a solution,
            //then remove the queen from the current position (backtrack)
            board[i][col]=0;
        }
    }
    //If no safe position is found for the current column, return false
    return false;
}
//Function to solve the N-Queens problem
void solveNQueens(){
    int board[N][N]={{0}}; //Initialize the chessboard with zeros
    //Call the recursive backtracking function to solve the problem
    if(!solveNQueensUtil(board,0)){
        printf("Solution does not exist.\n");
    }else{
        //If a solution is found, print the final placement of queens
        printf("My name is Arshdeep Kaur\n");
        printf("My Sap ID is 500107135\n");
        printSolution(board);
    }
}
//Main function
int main(){
    solveNQueens(); //Call the function to solve and print the N-Queens problem
    return 0;
}
