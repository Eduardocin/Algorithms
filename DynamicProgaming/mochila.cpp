#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int KnapsackBottomUp(int capacity, int numItens, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp) {
    
    for(int i = 0; i <= numItens; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(weight[i] <= j) {
                int val1 = dp[i - 1][j];
                int val2 = value[i] + dp[i - 1][j - weight[i]];
                dp[i][j] = max(val1, val2);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[numItens][capacity];

}


int main() {
    int numCases;

    cin >> numCases;

    while(numCases--) {
        int capacity, numItens;
        cin >> capacity >> numItens;

        vector<vector<int>> knapsack(numItens + 1, vector<int>(capacity + 1, 0));
        vector<int> weights(numItens + 1, 0);
        vector<int> values(numItens + 1, 0);
        
        
        for(int i = 1; i <= numItens; i++) {
            cin >> weights[i] >> values[i];
        }

        int mostValue = 0;
        mostValue = KnapsackBottomUp(capacity, numItens, values, weights, knapsack);


        cout << mostValue << endl;
    }

    return 0;
}