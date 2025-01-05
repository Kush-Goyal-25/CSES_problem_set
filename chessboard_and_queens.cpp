#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define ll long long

int main() {
    vector<string> chessboard(8);
    for (int i = 0; i < 8; i++) {
        cin >> chessboard[i];
    }

    int count = 0;  // Initialize count to 0
    vector<int> colum(8);
    iota(colum.begin(), colum.end(), 0);  // Fill with {0, 1, 2, ..., 7}

    do {
        bool valid = true;
        vector<bool> mainDiagonal(15, false);  // For i + colum[i]
        vector<bool> antiDiagonal(15, false); // For i - colum[i]

        for (int i = 0; i < 8; i++) {
            if (chessboard[i][colum[i]] != '.') {  // Check if the cell is not empty
                valid = false;
                break;
            }

            // Check diagonal constraints
            if (mainDiagonal[i + colum[i]] || antiDiagonal[i - colum[i] + 7]) {
                valid = false;
                break;
            }

            mainDiagonal[i + colum[i]] = true;
            antiDiagonal[i - colum[i] + 7] = true;
        }

        if (valid) {
            count++;  // Increment count for a valid arrangement
        }

    } while (next_permutation(colum.begin(), colum.end()));

    cout << count << endl;
    return 0;
}
