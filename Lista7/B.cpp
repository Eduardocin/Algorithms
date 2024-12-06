#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, j; // Dimensões do labirinto e número de espinhos evitáveis
vector<vector<char>> maze; // Labirinto
vector<vector<int>> visited; // Marcação de células visitadas

vector<pair<int, int>> directions = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

// Função para verificar se a posição é válida
bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] != '#';
}

bool dfs(int r, int c, int spikesAvoided, bool foundTreasure) {
    // Se encontrar o tesouro, definir como encontrado
    if (maze[r][c] == 'x') {
        foundTreasure = true;
    }

    // Se voltar à entrada com o tesouro encontrado, sucesso
    if (foundTreasure && maze[r][c] == '@') {
        return true;
    }

    // Marcar a célula como visitada
    visited[r][c] = 1;

    // Tentar todos os movimentos possíveis
    for (const auto& dir : directions) {
        int newR = r + dir.first;
        int newC = c + dir.second;

        // Se a nova posição for válida e não visitada
        if (isValid(newR, newC) && visited[newR][newC] == 0) {
            int newSpikesAvoided = spikesAvoided;
            if (maze[newR][newC] == 's') {
                newSpikesAvoided++;
            }

            // Verificar se pode evitar mais espinhos
            if (newSpikesAvoided <= j) {
                if (dfs(newR, newC, newSpikesAvoided, foundTreasure)) {
                    return true;
                }
            }
        }
    }

    // Desmarcar a célula para permitir outras explorações
    visited[r][c] = 0;
    return false;
}

int main() {
    cin >> n >> m >> j;

    maze.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m, 0));

    pair<int, int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                start = {i, j};
            }
        }
    }

    if (dfs(start.first, start.second, 0, false)) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
