#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int numRows, numColumns, maxSpikesAvoid;

bool isValid(int row, int col, int countSpikes, vector<vector<char>>& maze) {
    if (row < 0 || row >= numRows || col < 0 || col >= numColumns) // Check bounds
        return false;
    if (maze[row][col] == '#') // Wall
        return false;
    if (maze[row][col] == 's' && countSpikes >= maxSpikesAvoid) // Spike limit exceeded
        return false;
    return true;
}

bool exploreMaze(int row, int col, int& countSpikes, bool& foundTreasure, vector<vector<char>>& maze) {
    // Goal 
    if (maze[row][col] == 'x') {
        foundTreasure = true;
        return maxSpikesAvoid >= 2 * countSpikes;
    }

    // explore and backtracking
    char currentCell = maze[row][col];
    if (currentCell == 's') {
        countSpikes++;
    }
    maze[row][col] = '#';

    for (auto move : moves) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if (isValid(newRow, newCol, countSpikes, maze)) {
            if (exploreMaze(newRow, newCol, countSpikes, foundTreasure, maze)) {
                return true;
            }
        }
    }

    maze[row][col] = currentCell;
    if (currentCell == 's') {
        countSpikes--;
    }

    return false;
}

int main() {
    cin >> numRows >> numColumns >> maxSpikesAvoid;
    vector<vector<char>> maze(numRows, vector<char>(numColumns));
    
    bool treasureFound = false;
    int countSpikes = 0;
    pair<int, int> start;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                start = make_pair(i, j);
            }
        }
    }

    if (exploreMaze(start.first, start.second, countSpikes, treasureFound, maze)) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
