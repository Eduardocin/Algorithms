#include <bits/stdc++.h>

using namespace std;
/*
    backtracking blueprint
    #choices = available options
    #constraints = constraints on the choices
    #goal = the desired outcome

*/

bool isValid(vector<int>& nums, int numEle, int i, int S, int currentSum){
    //contrains
    if(currentSum + nums[i] > S) return false; // not is possible to add this number
    
    int temp = 0;
    for(int i = 0; i < numEle; i++) {
        temp += nums[i];
    }
    if(temp + currentSum < S ) return false;// not possible to reach the target sum

    return true;
    }

void findSubsets(vector<int>& nums, int& numSubsets, int currentSum, int S, int numEle, int index){
    //goal: find all subsets that sum up to the target sum
    if(currentSum == S){
        numSubsets++;
        return;
    }

    for(int i = index; i < numEle; i++) {// explore all possible choices
        if(isValid(nums, numEle, i, S, currentSum)){ // if current number is valid to add
            int newSum = currentSum + nums[i]; // add current number to the current sum
            int newIndex = i + 1; // update the index to avoid revisiting the same number
            findSubsets(nums, numSubsets, newSum, S, numEle, newIndex); // recursive call to explore the next choice
        }
    }
}


int main() {
    int numCases;
    cin >> numCases;
    while(numCases--) {
        int numElements;
        cin >> numElements;
        vector<int> arr(numElements);

        for(int i = 0; i < numElements; i++) {
            cin >> arr[i];
        }

        int targetSum;
        cin >> targetSum;

        int numSubsets = 0;
        findSubsets(arr, numSubsets, 0, targetSum, numElements, 0);

        cout << numSubsets << endl;

    }




    return 0;
}