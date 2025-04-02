#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Directions: Down, Right, Up, Left
const int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const char moves[4] = {'D', 'R', 'U', 'L'};
bool visited[7][7] = {false};
int countPaths = 0;

void dfs(int x, int y, int step, const string &path);
bool isValid(int x, int y);

int main() {
    cout << "Enter the 48-character path description: ";
    string path;
    cin >> path;

    if (path.length() != 48) {
        cout << "Invalid input. Please enter exactly 48 characters." << endl;
        return 0;
    }

    // Initialize the starting point as visited
    visited[0][0] = true;
    dfs(0, 0, 0, path);
    cout << "Total number of valid paths: " << countPaths << endl;

    return 0;
}

void dfs(int x, int y, int step, const string &path) {
    // Base case: If all steps are completed, check if we're at the bottom-left corner
    if (step == 48) {
        if (x == 6 && y == 0) {
            countPaths++;
        }
        return;
    }

    // Prune paths if trapped in a dead end or invalid split paths
    if ((x == 0 || x == 6) && (y > 0 && y < 6) && !isValid(x, y - 1) && !isValid(x, y + 1)) return;
    if ((y == 0 || y == 6) && (x > 0 && x < 6) && !isValid(x - 1, y) && !isValid(x + 1, y)) return;

    // Get the current move from the path
    char move = path[step];

    for (int d = 0; d < 4; d++) {
        // Skip directions that don't match the current move unless it's a wildcard
        if (move != '?' && moves[d] != move) continue;

        int nx = x + directions[d][0];
        int ny = y + directions[d][1];

        // Proceed only if the next position is valid
        if (isValid(nx, ny)) {
            visited[nx][ny] = true;
            dfs(nx, ny, step + 1, path);
            visited[nx][ny] = false; // Backtrack
        }
    }
}

bool isValid(int x, int y) {
    // Ensure the position is within bounds and not already visited
    return x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y];
}
