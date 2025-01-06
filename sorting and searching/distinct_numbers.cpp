
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <math.h>
#include <unordered_set>
#include <vector>
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;

  set<int> distinct;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    distinct.insert(x);
  }

  cout << distinct.size() << endl;
}
