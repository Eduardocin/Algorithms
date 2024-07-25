#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 
    choices: movimentos possíveis do cavalo em um tabuleiro
    contrains: as casas visitadas não podem ser visitadas novamente, a possição de movimentos não pode ultrapassar as dimensões do tabuleiro e
    o cavalo deve iniciar na posição superior esquerda do tabuleiro
    goal: encontrar o número máximo de casas alcançadas pelo cavalo
*/



vector<pair<int, int>> knightMoves = {
    {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
};

// Função para verificar se a posição é válida e não visitada
bool isValidMove(const vector<vector<int>>& board, int x, int y) {
    // Verifica se as coordenadas x e y estão dentro dos limites do tabuleiro
    bool withinBoardLimits = (x >= 0 && x < 10 && y >= 0 && y < 10);

    // Verifica se a posição no tabuleiro é válida (não visitada e acessível)
    bool positionIsAccessible = withinBoardLimits && (board[x][y] == 1);

    return positionIsAccessible;
}

// Função de backtracking para explorar todas as casas alcançáveis pelo cavalo
void exploreReachableSquares(int x, int y, int currentCount, int &maxReachable, vector<vector<int>>& board) {
    maxReachable = max(maxReachable, currentCount); // Atualiza o número máximo de casas alcançadas
    for (const auto& move : knightMoves) { // Tenta todos os 8 movimentos possíveis do cavalo
        int newX = x + move.first;
        int newY = y + move.second;
        if (isValidMove(board, newX, newY)) { // Verifica se o movimento é válido
            board[newX][newY] = 2; // Marca a posição como visitada
            exploreReachableSquares(newX, newY, currentCount + 1, maxReachable, board); // Chama a função recursivamente
            board[newX][newY] = 1; // Desmarca a posição (backtracking)
        }
    }
}

int main() {
    int caseNumber = 1; // Número do caso de teste
    int numRows;   // Número de linhas do tabuleiro

    while (cin >> numRows, numRows != 0) { // Lê o número de linhas do tabuleiro e verifica se é zero
        vector<vector<int>> board(10, vector<int>(10, 0)); // Inicializa o tabuleiro 10x10 com zeros
        int totalSquares = 0; // Total de quadrados válidos
        int startColumn;      // Coluna inicial do cavalo

        for (int i = 0; i < numRows; ++i) { // Lê cada linha do tabuleiro
            int offset, numSquares;
            cin >> offset >> numSquares; // Lê o deslocamento e o número de quadrados na linha
            totalSquares += numSquares;  // Atualiza o total de quadrados válidos
            if (i == 0) { // Salva a coluna inicial da primeira linha
                startColumn = offset;
            }
            for (int j = offset; j < offset + numSquares; ++j) { // Marca os quadrados válidos na linha
                board[i][j] = 1;
            }
        }

        int maxReachable = 0; // Inicializa o número máximo de quadrados alcançáveis
        board[0][startColumn] = 2; // Marca a posição inicial como visitada
        exploreReachableSquares(0, startColumn, 1, maxReachable, board); // Inicia a exploração
        
        for (const auto& row : board) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }




        int unreachableSquares = totalSquares - maxReachable; // Calcula o número de quadrados inalcançáveis

        // Imprime o resultado para o caso atual
        cout << "Case " << caseNumber << ", " << unreachableSquares;
        if (unreachableSquares == 1) {
            cout << " square can not be reached." << endl;
        } else {
            cout << " squares can not be reached." << endl;
        }

        caseNumber++; // Incrementa o número do caso
    }

    return 0; // Termina o programa
}
