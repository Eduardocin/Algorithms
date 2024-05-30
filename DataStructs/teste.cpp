#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int n = 5;  // Assuming you want a vector of 5 elements

    v.resize(n);  // Resize the vector to have n elements

    fill(v.begin(), v.end(), 10);  // Fill the vector with the value 10

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}