#include <iostream>   
#include <vector>
using namespace std;


int N;  // Variável global para armazenar o tamanho do tabuleiro (N x N)
vector<vector<vector<int>>> solutions;  // Vetor global para armazenar todas as soluções encontradas

// Função que verifica se é seguro colocar uma rainha na posição (row, col)
bool isValid(vector<vector<int>>& M, int row, int col) {
    for (int i = 0; i < row; ++i) {  // Verifica a coluna acima da posição atual
        if (M[i][col] == 1) return false;  // Se encontrar uma rainha na mesma coluna, retorna falso
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {  // Verifica a diagonal principal acima da posição atual
        if (M[i][j] == 1) return false;  // Se encontrar uma rainha na diagonal principal, retorna falso
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j) {  // Verifica a diagonal secundária acima da posição atual
        if (M[i][j] == 1) return false;  // Se encontrar uma rainha na diagonal secundária, retorna falso
    }
    return true;  // Se nenhuma rainha for encontrada nas verificações, retorna verdadeiro
}

// Função recursiva para resolver o problema das N rainhas
bool qns(int l, vector<vector<int>>& M) {
    if (l == N) {  // Se todas as rainhas forem colocadas (l == N), adiciona a solução e retorna verdadeiro
        solutions.push_back(M);  // Adiciona a matriz atual às soluções
        return true;
    } else {
        bool res = false;  // Variável para acumular o resultado das chamadas recursivas
        for (int i = 0; i < N; ++i) {  // Itera sobre todas as colunas da linha atual
            if (isValid(M, l, i)) {  // Se é seguro colocar uma rainha na posição (l, i)
                M[l][i] = 1;  // Coloca a rainha na posição (l, i)
                res = qns(l + 1, M) || res;  // Chama recursivamente para a próxima linha e acumula o resultado
                M[l][i] = 0;  // Remove a rainha da posição (l, i) (backtracking)
            }
        }
        return res;  // Retorna o resultado acumulado
    }
}

int main() {
    cin >> N;  // Lê o valor de N (tamanho do tabuleiro)
    if (N < 1) {  // Verifica se N é pelo menos 1
        cout << "N must be at least 1" << endl;  // Exibe mensagem de erro se N for menor que 1
        return 1;  // Encerra o programa com código de erro
    }
    vector<vector<int>> M(N, vector<int>(N, 0));  // Inicializa uma matriz NxN com zeros
    qns(0, M);  // Chama a função recursiva para resolver o problema das N rainhas
    cout << solutions.size() << "\n\n";  // Imprime o número de soluções encontradas
    for (size_t i = 0; i < solutions.size(); ++i) {  // Itera sobre todas as soluções
        cout << "Sol. " << i + 1 << ":\n";  // Imprime o índice da solução
        for (int r = 0; r < N; ++r) {  // Itera sobre todas as linhas da solução
            for (int c = 0; c < N; ++c) {  // Itera sobre todas as colunas da solução
                cout << solutions[i][r][c] << " ";  // Imprime o valor da posição (r, c) na solução
            }
            cout << "\n";  // Imprime uma nova linha após cada linha da solução
        }
        cout << "\n";  // Imprime uma nova linha após cada solução
    }
    return 0;  // Encerra o programa com código de sucesso
}
