#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<vector<int>>> solutions;

bool isValid(vector<vector<int>>& M, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (M[i][col] == 1) return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (M[i][j] == 1) return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j) {
        if (M[i][j] == 1) return false;
    }
    return true;
}

void qns(int l, vector<vector<int>>& M) {
    if (l == N) {
        solutions.push_back(M);
        return;
    } else {
        for (int i = 0; i < N; ++i) {
            if (isValid(M, l, i)) {
                M[l][i] = 1;
                qns(l + 1, M);
                M[l][i] = 0;
            }
        }
    }
}

int main() {
    cin >> N;

    vector<vector<int>> M(N, vector<int>(N, 0));
    qns(0, M);
    cout << solutions.size() << "\n";
    for (size_t i = 0; i < solutions.size(); ++i) {
        cout << "Sol. " << i + 1 << ":" << endl;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                cout << solutions[i][r][c] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
