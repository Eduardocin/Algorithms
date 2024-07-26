#include <iostream>
#include <vector>

using namespace std;

int N; // global variable to store the size of the array

bool isValid(vector<vector<int>>& M, int row, int col){
    for(int i = 0; i < row; i++)
    {
        if(M[i][col] == 1) //check each row in the same column
            return false;
    }
    //verifica as diagonais
    for(int i = row - 1, j = col -1; i >= 0 && j >= 0; i--, j--)
    {
        if(M[i][j] == 1) // check principal diagonal
            return false;
    }
    
    for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if(M[i][j] == 1)  // check secondary diagonal
            return false;
    }

    return true; // if no conflicts found, return true
}

bool solveNQueens(vector<vector<int>>& M, int l){
    if(l == N){ // if all queens are placed, return true
        return true;
    }
    
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(isValid(M, l, i))              // if the current position is valid
            {
                M[l][i] = 1;                  // place the queen at current position
                if(solveNQueens(M, l + 1))    // recursively try to place the queens in the remaining rows
                    return true;
                M[l][i] = 0;                  // remove the queen from the current position
            }
        }
        return false; 
    }
}

int main(){
    cin >> N;

    vector<vector<int>> M(N, vector<int>(N, 0)); // initialize the chessboard with all cells empty

    // call the function to solve the problem
    if(solveNQueens(M, 0))
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


    for(int j = 0; j < N; j++){
        for(int k = 0; k < N; k++){
            cout << M[j][k] << " ";
        }
        cout << endl;
    }   


    return 0;
}