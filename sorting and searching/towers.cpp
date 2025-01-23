#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n;
    cin >> n;

    multiset<long long> towers;

    for (long long i = 0; i < n; i++) {
        long long cube;
        cin >> cube;

        auto it = towers.upper_bound(cube);

        if (it != towers.end()) {
            towers.erase(it);
        }

        towers.insert(cube);
    }

    cout << towers.size() << endl;

    return 0;
}
