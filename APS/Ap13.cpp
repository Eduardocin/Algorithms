#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função auxiliar para imprimir o subconjunto encontrado
void printSubset(const vector<int>& subset) {
    vector<int> sortedSubset = subset;
    sort(sortedSubset.begin(), sortedSubset.end());
    for (int num : sortedSubset) {
        cout << num << " ";
    }
    cout << endl;
}

// Função de backtracking para encontrar o subconjunto cuja soma é igual a S
bool findSubset(vector<int>& C, vector<int>& subset, int n, int S, int index, int currentSum) {
    if (currentSum == S) {
        printSubset(subset);
        return true;
    }
    if (currentSum > S || index >= n) {
        return false;
    }

    // Incluir o elemento atual no subconjunto
    subset.push_back(C[index]);
    if (findSubset(C, subset, n, S, index + 1, currentSum + C[index])) {
        return true;
    }

    // Não incluir o elemento atual no subconjunto
    subset.pop_back();
    return findSubset(C, subset, n, S, index + 1, currentSum);
}

int main() {
    int n, S;
    cin >> n >> S;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    vector<int> subset;
    if (!findSubset(C, subset, n, S, 0, 0)) {
        cout << "No solution found" << endl;
    }

    return 0;
}