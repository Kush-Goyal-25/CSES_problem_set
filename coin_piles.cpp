
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;
#define ll long long

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;

    if (a > b) {
      swap(a, b);
    }
    if (b > a * 2 || (a + b) % 3 != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
