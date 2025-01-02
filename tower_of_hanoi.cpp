#include <bits/stdc++.h>
#include <cmath> // For pow function
#include <iostream>
#include <string> // For pow function
using namespace std;

void answer(long n, string source, string helper, string target) {
  if (n == 1) {
    cout << source << " " << target << endl;
    return;
  }
  answer(n - 1, source, target, helper);
  cout << source << " " << target << endl;
  answer(n - 1, helper, source, target);
}

int main() {
  long n;
  cin >> n;

  long moves = (1L << n) - 1; // 2^n - 1, using bitwise left shift
  cout << moves << endl;

  answer(n, "1", "2", "3");

  return 0;
}
