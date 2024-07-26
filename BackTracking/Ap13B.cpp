#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    choices
    constraints
    goal
*/

bool isValid(vector<int>& C, int numElements, int index, int S, int currentSum) {
    
    // constraints
    
    //checkar se o valor ultrapassa o objetivo
    if (currentSum + C[index] > S) { // não é possível adicionar mais moedas
        return false;
    }
    
    //checkar se é possível chegar no target
    int sum = 0;
    for(int i = index; i < numElements; i++) {
        sum += C[i];
    }
    if (currentSum + sum < S) return false; // não é possível alcançar o objetivo


    return true;
}

bool findSubset(vector<int>& C, vector<int>& subset, int numElements, int S, int currentSum, int startIndex) {
    // goal
    if (currentSum == S) {
        return true;
    }

    // choices
    for (int i = startIndex; i < numElements; i++) {
        if (isValid(C, numElements, i, S, currentSum)) {
            
            subset.push_back(C[i]); // adicionar o elemento ao subset

            if (findSubset(C, subset, numElements, S, currentSum + C[i], i + 1)) {
                return true;
            }

            subset.pop_back(); // backtracking the element
        }
    }

    return false;
}

int main() {
    int numElements, S;
    cin >> numElements >> S;

    vector<int> C(numElements);

    for (int i = 0; i < numElements; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end()); // Ordenar os elementos do array para facilitar a busca binária

    vector<int> subset;
    if (findSubset(C, subset, numElements, S, 0, 0)) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}