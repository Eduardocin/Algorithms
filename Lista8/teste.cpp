#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Função para calcular o custo mínimo para o sapo chegar à pedra N
int min_cost(int N, int K, const vector<int>& heights) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;  // O custo para estar na primeira pedra é 0

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
            }
        }
    }

    return dp[N-1];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // Calcular o custo mínimo e imprimir o resultado
    cout << min_cost(N, K, heights) << endl;

    return 0;
}
