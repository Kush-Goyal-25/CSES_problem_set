
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long

vector<string> generateGrayCode(int n) {
  vector<string> graycode;

  graycode.push_back("0");
  graycode.push_back("1");

  for (int i = 2; i <= n; i++) {
    int size = graycode.size();

    for (int j = size - 1; j >= 0; j--) {
      graycode.push_back("1" + graycode[j]);
    }
    for (int j = 0; j < 1; j++) {
      graycode[j] = "0" + graycode[j];
    }
  }
  return graycode;
}

int main() {
  int n;
  cin >> n;

  vector<string> graycode = generateGrayCode(n);
  for (const string &code : graycode) {
    cout << code << endl;
  }
  return 0;
}
