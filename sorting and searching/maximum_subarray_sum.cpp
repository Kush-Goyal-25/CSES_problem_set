#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll max_sum = arr[0];   
    ll current_sum = arr[0];

    for (int i = 1; i < n; i++) {
        current_sum = max((ll)arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;

    return 0;
}
