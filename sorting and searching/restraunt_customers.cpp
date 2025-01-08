#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> events;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    events.emplace_back(a, 1);
    events.emplace_back(b, -1);
  }

  sort(events.begin(), events.end());

  int current = 0;
  int maxi = 0;
  for (auto &event : events) {
    current += event.second;
    maxi = max(maxi, current);
  }
  cout << maxi << endl;
}
