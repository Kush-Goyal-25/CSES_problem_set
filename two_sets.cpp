
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;

  if (sum % 2 != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    vector<ll> f;
    vector<ll> s;
    if (n % 2 == 0) {
      for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
          f.push_back(i + 1LL);
          f.push_back(n - i);
        } else {
          s.push_back(i + 1LL);
          s.push_back(n - i);
        }
      }
    } else {
      for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
          f.push_back(i + 1LL);
          f.push_back(n - i - 1);
        } else {
          s.push_back(i + 1LL);
          s.push_back(n - i - 1);
        }
      }
      if (f.size() > s.size()) {
        s.push_back(n);
      } else {
        f.push_back(n);
      }
    }

    cout << f.size() << endl;
    for (int i = 0; i < f.size(); i++) {
      cout << f[i] << " ";
    }
    cout << endl;

    cout << s.size() << endl;
    for (int i = 0; i < s.size(); i++) {
      cout << s[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
