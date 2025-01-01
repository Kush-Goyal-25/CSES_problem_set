#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  while (n >= 5) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans << endl;
}

//
