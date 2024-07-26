#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*

    choices
    contrains
    goal

*/


bool isValid(vector<int>& C, int size, int sum, int pos, int currentSum) {
    if(currentSum + C[pos] > sum) return false;
    
    int temp = 0;
    for(int i = pos; i < size; i++ ){
        temp += C[i];
    }
    if(temp + currentSum < sum) return false;

    return true;
        
}

void findSubsets(vector<int>& nums, int& numSubsets, int currentSum, int S, int sizeNums, int index){
    if(currentSum == S){
        numSubsets++;
        return;
    }

    for(int i = index; i < sizeNums; i++){
        if(isValid(nums, sizeNums, S, i, currentSum + nums[i])){
            findSubsets(nums, numSubsets, currentSum + nums[i], S, sizeNums, i + 1);
        }
    }

}




int main() {
    return 0;
}
