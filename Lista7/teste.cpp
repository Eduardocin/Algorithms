#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> knightMoves = {
    {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
};

bool isValid(int r, int c, const vector<vector<int>>& board) {
    bool limitBoard = (r >= 0 && r < board.size()) && (c >= 0 && c < board[r].size());
    bool validCell = limitBoard && board[r][c] == 1;
    
    return validCell;}

void KnighsBacktracking(int r, int c, vector<vector<int>>& board, int& currentCount, int& maxCount) {
    
    board[r][c] = 2;
    currentCount++;
    maxCount = max(maxCount, currentCount);

    // all possible knight moves
    for (const auto& move : knightMoves) {
        int newR = r + move.first;
        int newC = c + move.second;

        if (isValid(newR, newC, board)) {
            KnighsBacktracking(newR, newC, board, currentCount, maxCount);
        }
    }

    board[r][c] = 1;
    currentCount--;
}



int main() {
    int caseNumber = 1;
    int numRows;

    while (cin >> numRows && numRows != 0) {
        vector<vector<int>> board(numRows);

        int totalValid = 0;
        int startPosition = -1;

        // Initialize the board
        for (int i = 0; i < numRows; i++) {
            int offset, numSquares;
            cin >> offset >> numSquares;

            board[i].resize(offset + numSquares, 0);
            totalValid += numSquares;

            for (int j = offset; j < offset + numSquares; j++) {
                board[i][j] = 1; 
            }

            if (i == 0) {
                startPosition = offset;
            }
        }


        //backtracking 
        int maxCount = 0;
        int currentCount = 0;
        
        KnighsBacktracking(0, startPosition, board, currentCount, maxCount);        



        int unreachableCount = totalValid - maxCount;

        cout << "Case " << caseNumber << ", " << unreachableCount;
        if (unreachableCount == 1) {
            cout << " square can not be reached." << endl;
        } else {
            cout << " squares can not be reached." << endl;
        }

        caseNumber++;
    }

    return 0;
}
