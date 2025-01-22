#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  long long target = 1;
  for (long long coin : arr) {
    if (coin > target) {
      break;
    }
    target += coin;
  }

  cout << target << endl;

  return 0;
}
