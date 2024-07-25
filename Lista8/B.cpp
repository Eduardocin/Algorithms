#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Função para calcular o custo mínimo para o sapo chegar à pedra N
int min_cost(int jump, vector<int>& heights) {
    int n = heights.size();
    
    vector<int> solution(n, INT_MAX);
    solution[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= jump; ++j) {
            if (i - j >= 0) {
                int val1 = solution[i - j] + abs(heights[i] - heights[i - j]);  // Custo para saltar 
                int val2 = solution[i];  // Custo para andar
                solution[i] = min(val1, val2);
            }
        }
    }

    return solution[n - 1];
}

int main() {
    int numStones, jumpRange;
    cin >> numStones >> jumpRange;

    vector<int> heights(numStones);
    
    for (int i = 0; i < numStones; ++i) {
        cin >> heights[i];
    }

    // Calcular o custo mínimo e imprimir o resultado
    cout << min_cost(jumpRange, heights) << endl;

    return 0;
}
