#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
  ll n;
  cin >> n;

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    ans = ans * 2;
    ans = ans % MOD;
  }
  cout << ans << endl;
}
