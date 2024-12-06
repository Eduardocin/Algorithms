#include <bits/stdc++.h>

using namespace std;


int SolverowCoins(vector<int>& coins, vector<int>& F){
    
    F[0] = 0;
    F[1] = coins[1];

    int n = coins.size();
    for(int i = 2; i < n; i++){
        int val1 = coins[i] + F[i -2];
        int val2 = F[i - 1];
        F[i] = max(val1, val2);
        

    }

    return F[n-1];
}




int main(){
    int numCases;
    cin >> numCases;
    int caso = 1;

    while(numCases--){
        int numCoins;
        cin >> numCoins;

        vector<int> coins(numCoins+1,0);
        vector<int> result(numCoins +1,0);
        
        for(int i = 1; i <= numCoins; i++){
            cin >> coins[i];
        }
        
        int maxVal = SolverowCoins(coins, result);

        stack<int> q;

        for(int i = numCoins; i > 0; i--){
            if(result[i] != result[i-1]){
                q.push(coins[i]);
                i--;
            }
            else{
                if(i == numCoins){
                    q.push(coins[i-1]);
                    i = i -2;
                }
                else{
                    q.push(coins[i-1]);
                    i--;
                }

            }
        }

        cout << "Caso " << caso << ": ";        
        
        while(!q.empty()){
            int val = q.top();
            q.pop();
            if(q.size() >= 1){
                cout << val << "+";
            }
            else{
                cout << val;
            }
        }
        if(maxVal == 0){
            cout << "0";
        }
    
        
        cout << "=" << maxVal << endl;
        
        caso++;
    }

    return 0;
}
