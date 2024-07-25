#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int KnapsackTopDown(int i, int j, vector<int>& values, vector<int>& weights, vector<vector<int>>& knapsackMatrix) {
    
    //definir a primeira linha e coluna como 0
    for(int x = 0; x <= j; x++) {
        knapsackMatrix[0][x] = 0;
    }
    for(int x = 0; x <= i; x++) {
        knapsackMatrix[x][0] = 0;
    }

    if (knapsackMatrix[i][j] < 0) {
        if (j < weights[i]) {
            knapsackMatrix[i][j] = KnapsackTopDown(i-1, j, values, weights, knapsackMatrix);
        } else {
            int val1 = values[i] + KnapsackTopDown(i-1, j - weights[i], values, weights, knapsackMatrix);
            int val2 = KnapsackTopDown(i-1, j, values, weights, knapsackMatrix);
            knapsackMatrix[i][j] = max(val1, val2);
        }
    }
    return knapsackMatrix[i][j];
}

int KnapsackBottomUp(int numItems, int backCapacity, vector<int>& values, vector<int>& weights, vector<vector<int>>& knapsackMatrix) {
    for (int i = 0; i <= numItems; i++) {
        for (int j = 0; j <= backCapacity; j++) {
            if (i == 0 || j == 0) {
                knapsackMatrix[i][j] = 0;
            } else if (weights[i] <= j) {
                int val1 = values[i] + knapsackMatrix[i-1][j - weights[i]];
                int val2 = knapsackMatrix[i-1][j];
                knapsackMatrix[i][j] = max(val1, val2);
            } else {
                knapsackMatrix[i][j] = knapsackMatrix[i-1][j];
            }
        }
    }
    return knapsackMatrix[numItems][backCapacity];
}

int main() {
    int numItems, backCapacity;
    cin >> backCapacity >> numItems;

    vector<vector<int>> knapsackMatrix(numItems + 1, vector<int>(backCapacity + 1, -1)); 
    vector<int> values(numItems + 1, 0); 
    vector<int> weights(numItems + 1, 0); 
    
    for (int i = 1; i <= numItems; i++) {
        cin >> weights[i] >> values[i];  
    }

    int max_value = KnapsackTopDown(numItems, backCapacity, values, weights, knapsackMatrix);

    cout << max_value << endl;


    return 0;
}