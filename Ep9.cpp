#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int>& elements, int index, int currentSum, int target) {
    if (currentSum + elements[index] > target) return false;
    return true;
}

bool findSubsets(vector<int>& elements, vector<int>& result, int currentSum, int target, int index) {
    if (currentSum == target) {
        return true;
    }

    for (int i = index; i < elements.size(); i++) {
        if (isValid(elements, i, currentSum, target)) {
            result.push_back(elements[i]);
            int newSum = currentSum + elements[i];
            if (findSubsets(elements, result, newSum, target, i + 1)) {
                return true;
            }
            result.pop_back();
        }
    }

    return false;
}

int main() {
    int numCases;
    cin >> numCases;

    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        int numElements;
        cin >> numElements;

        vector<int> elements(numElements);

        for (int i = 0; i < numElements; i++) {
            cin >> elements[i];
        }

        int target;
        cin >> target;

        vector<int> subSet;
        if (findSubsets(elements, subSet, 0, target, 0)) {
            cout << "Caso " << caseNum << ": {";
            for (int i = 0; i < subSet.size(); i++) {
                cout << subSet[i];
                if (i < subSet.size() - 1) cout << ",";
            }
            cout << "}" << endl;
        } else {
            cout << "Caso " << caseNum << ": -1" << endl;
        }
    }

    return 0;
}
