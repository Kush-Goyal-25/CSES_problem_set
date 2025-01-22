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

  if (n <= 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> arr(n);
  vector<int> ans(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans[arr[i]] = i;
  }
  int count = 1;

  for (int i = 2; i <= n; i++) {
    if (ans[i] < ans[i - 1]) {
      count++;
    }
  }
  cout << count << endl;
}

//    2 1 4 0 3
