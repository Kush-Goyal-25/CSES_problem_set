#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> map;

    for (int i = 0; i < n; i++) {
        int result = x - arr[i];
        if (map.find(result) != map.end()) {
            int idx1 = map[result] + 1; // 1-based index
            int idx2 = i + 1;          // 1-based index
            if (idx1 < idx2) {
                cout << idx1 << " " << idx2 << endl;
            } else {
                cout << idx2 << " " << idx1 << endl;
            }
            return 0;
        }
        map[arr[i]] = i;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
