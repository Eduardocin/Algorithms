#include <bits/stdc++.h>
using namespace std;

vector<int> solution;

int coinRow(vector<int> coins) {
    solution[0] = 0;
    solution[1] = coins[1];
    int n = coins.size() - 1;

    for (int i = 2; i <= n; i++) {
        solution[i] = max(coins[i] + solution[i - 2], solution[i - 1]);
    }

    return solution[n];
}



int main() {
    int numCases;
    cin >> numCases;

    while (numCases--) {
        int numCoins;
        cin >> numCoins;
        vector<int> coins(numCoins + 1);
        solution.resize(numCoins + 1, 0);

        for (int i = 1; i <= numCoins; i++) {
            cin >> coins[i];
        }

        cout << coinRow(coins) << endl;
    }

    return 0;
}
