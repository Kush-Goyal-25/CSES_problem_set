#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int count = 0;
    int i = 0, j = n - 1;

    while (i <= j) {
        if (weights[i] + weights[j] <= x) {
            i++;
        }
        j--;
        count++; 
    }

    cout << count << endl;
    return 0;
}
