#include <iostream>
#include <map>
#include <sstream>
using namespace std;

class FastInput {
private:
    static const int BUFFER_SIZE = 1 << 16;
    char buffer[BUFFER_SIZE];
    int bufferPointer, bytesRead;

    void fillBuffer() {
        bytesRead = fread(buffer, 1, BUFFER_SIZE, stdin);
        bufferPointer = 0;
    }

    char readChar() {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return bufferPointer < bytesRead ? buffer[bufferPointer++] : EOF;
    }

public:
    FastInput() : bufferPointer(0), bytesRead(0) {}

    int nextInt() {
        int ret = 0;
        char c = readChar();
        while (c <= ' ')
            c = readChar();
        bool neg = (c == '-');
        if (neg)
            c = readChar();
        do {
            ret = ret * 10 + (c - '0');
            c = readChar();
        } while (c >= '0' && c <= '9');
        return neg ? -ret : ret;
    }
};

int main() {
    FastInput input;
    int n = input.nextInt();
    int m = input.nextInt();

    map<int, int> concert_map;
    ostringstream res;

    for (int i = 0; i < n; i++) {
        int temp = input.nextInt();
        concert_map[temp]++;
    }

    for (int i = 0; i < m; i++) {
        int temp = input.nextInt();
        auto it = concert_map.lower_bound(temp + 1);
        if (it == concert_map.begin()) {
            res << "-1\n";
        } else {
            --it;
            res << it->first << '\n';
            if (it->second == 1) {
                concert_map.erase(it);
            } else {
                it->second--;
            }
        }
    }

    cout << res.str();
    return 0;
}
