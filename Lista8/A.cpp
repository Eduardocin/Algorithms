#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

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

    int max_value = KnapsackBottomUp(numItems, backCapacity, values, weights, knapsackMatrix);

    cout << max_value << endl;


    return 0;
}