#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a}; // Store movies as {ending time, starting time}
    }

    // Sort movies by ending time
    sort(movies.begin(), movies.end());

    int count = 0;
    int last_end_time = 0;

    for (auto& movie : movies) {
        int start_time = movie.second;
        int end_time = movie.first;

        if (start_time >= last_end_time) {
            count++;
            last_end_time = end_time; // Update the end time of the last watched movie
        }
    }

    cout << count << endl;
    return 0;
}
