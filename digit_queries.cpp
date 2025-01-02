#include <iostream>
#include <string>
using namespace std;
#define ll long long

int main() {
    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        if (k <= 9) {
            cout << k << endl; 
        } else {
            ll length = 1;
            ll numcount = 9;
            ll str = 1;

            while (k > length * numcount) {
                k -= length * numcount;
                length++;
                numcount *= 10;
                str *= 10;
            }

            ll number = str + (k - 1) / length;
            int digitindex = (k - 1) % length;

            string numberstr = to_string(number);
            cout << numberstr[digitindex] - '0' << endl; 
        }
    }

    return 0;
}
