#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr1(n);
    vector<ll> arr2(m);

    // Input arrays
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int count = 0;
    int j = 0; // Pointer for arr2

    // Two-pointer approach
    for (int i = 0; i < n; i++) {
        while (j < m && arr2[j] < arr1[i] - k) {
            j++; // Move j forward if arr2[j] is too small
        }
        if (j < m && arr2[j] <= arr1[i] + k) {
            count++; // Found a match
            j++;     // Move j forward to avoid reusing the same element
        }
    }

    cout << count << endl;
    return 0;
}
