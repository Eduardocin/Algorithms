#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


/*
    choices
    contrains
    goals
*/

// check contrains
bool isValidMove(int x, int y, const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // Verifica se a célula está dentro dos limites e não está bloqueada ou já visitada
    return (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != 1 && matrix[x][y] != -1);
}

bool findPath(vector<vector<int>>& matrix, int r, int c, int& minMoves, int movesCount) {
    // goal
    if (matrix[r][c] == 3) {
        minMoves = movesCount;
        return true;
    }

    matrix[r][c] = -1; // Marcar a célula como visitada
    
    //choices
    for (auto& move : moves) {
        int newX = r + move.first;
        int newY = c + move.second;
        if (isValidMove(newX, newY, matrix)) {
            if (findPath(matrix, newX, newY, minMoves, movesCount + 1)) {
                return true; // Encontrado um caminho
            }
        }
    }
    
    matrix[r][c] = 0; // Desmarcar a célula para backtracking
    
    return false; // Não foi possível encontrar um caminho
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> matrix(M, vector<int>(N, 0));
    
    int startX = -1, startY = -1;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    
    int minMoves = -1;
    if (findPath(matrix, startX, startY, minMoves, 0)) {
        cout << minMoves << endl;
    } else {
        cout << "Labirinto Impossivel" << endl;
    }
    
    return 0;
}
