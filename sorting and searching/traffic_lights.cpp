#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long long x, n;
    cin >> x >> n;

    vector<long long> positions(n);
    for (long long i = 0; i < n; i++) {
        cin >> positions[i];
    }

    set<long long> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<long long> lengths;
    lengths.insert(x);

    for (long long i = 0; i < n; i++) {
        long long p = positions[i];

        // Find the nearest traffic lights
        auto it = lights.upper_bound(p);
        long long right = *it;
        long long left = *(--it);

        lengths.erase(lengths.find(right - left));

        lengths.insert(p - left);
        lengths.insert(right - p);

        lights.insert(p);

        cout << *(--lengths.end()) << " ";
    }

    cout << endl;
    return 0;
}
