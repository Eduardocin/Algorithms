#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CoinRow(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) return 0;
    if (n == 1) return coins[0];

    vector<int> F(n + 1);
    F[0] = 0;
    F[1] = coins[1];

    for (int i = 2; i < n; ++i) {
        F[i] = max(coins[i] + F[i-2], F[i-1]);
    }

    return F[n];
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        vector<int> coins(n+1);
        coins[0] = 0; // base case: no coins means no value

        for (int i = 1; i <= n; ++i) {
            cin >> coins[i];
        }

        // Compute and output the result
        cout << CoinRow(coins) << endl;
    }

    return 0;
}
