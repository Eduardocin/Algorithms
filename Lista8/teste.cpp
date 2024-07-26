#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bag;


int SolveKnapsack(int numItens, int knapsackCapcity, vector<int>& w, vector<int> v, vector<vector<int>>& bag){

    for(int i = 0; i <= numItens; i++){
        for(int j = 0; j <= knapsackCapcity; j++){
            if(i == 0 || j == 0){
                bag[i][j] = 0;
            }
            else if(w[i] <= j){
                int val1 = bag[i-1][j];
                int val2 = v[i] + bag[i-1][j-w[i]];
                bag[i][j] = max(val1, val2);
            }
            else{
                bag[i][j] = bag[i-1][j];
            }
        }
    }
    return bag[numItens][knapsackCapcity];

}


int main(){
    int numItens, knapsackCapcity;
    cin >> numItens >> knapsackCapcity;

    vector<int> values(numItens + 1, 0), weights(numItens + 1 , 0);
    bag.resize(numItens+1, vector<int>(knapsackCapcity+1, 0));


    for(int i = 1; i <= numItens; i++){
        cin >> weights[i] >> values[i];
    }

    int maxValue = SolveKnapsack(numItens, knapsackCapcity, weights, values, bag);
    cout << "Max Value: " << maxValue << endl;




    return 0;
}