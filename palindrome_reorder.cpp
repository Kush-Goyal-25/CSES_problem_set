#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;
#define ll long long

bool isPalin(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++, j--;
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  ll n = s.size();

  map<char, int> o;
  for (auto x : s) {
    o[x]++;
  }
  string w = "";

  for (auto x : o) {
    if (x.second % 2 == 1) {
      w += x.first;
      o[x.first]--;
    }
  }
  string begin = "";
  for (auto x : o) {
    for (int k = 0; k < x.second / 2; k++) {
      begin += x.first;
      o[x.first]--;
    }
  }
  string end = "";
  for (auto x : o) {
    for (int k = 0; k < x.second; k++) {
      end += x.first;
      o[x.first]--;
    }
  }
  reverse(end.begin(), end.end());
  string res = begin + w + end;

  if (isPalin(res)) {
    cout << res << endl;
  } else {
    cout << "NO SOLUTION" << endl;
  }
}
