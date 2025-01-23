#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) {
            rounds++;
        }
    }

    string result;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        unordered_set<int> affected;
        affected.insert(arr[a]);
        affected.insert(arr[b]);
        if (arr[a] > 1) affected.insert(arr[a] - 1);
        if (arr[a] < n) affected.insert(arr[a] + 1);
        if (arr[b] > 1) affected.insert(arr[b] - 1);
        if (arr[b] < n) affected.insert(arr[b] + 1);

        for (int num : affected) {
            if (num >= 1 && num < n && pos[num] > pos[num + 1]) {
                rounds--;
            }
        }

        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for (int num : affected) {
            if (num >= 1 && num < n && pos[num] > pos[num + 1]) {
                rounds++;
            }
        }

        result += to_string(rounds) + "\n";
    }

    cout << result;
    return 0;
}
