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

    list<int> children;
    for (int i = 1; i <= n; i++) {
        children.push_back(i);
    }

    list<int>::iterator it = children.begin();
    vector<int> removalOrder;

    while (!children.empty()) {
        it++;
        if (it == children.end()) it = children.begin();

        removalOrder.push_back(*it);
        it = children.erase(it);
        if (it == children.end()) it = children.begin();
    }

    for (int num : removalOrder) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
