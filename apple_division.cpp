
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum difference between two groups of weights
long findMinDifference(int index, long group1, long group2,
                       const vector<long> &weights) {
  // Base case: all apples are considered
  if (index == weights.size()) {
    return abs(group1 - group2);
  }

  // Try putting the current apple in group 1
  long diff1 =
      findMinDifference(index + 1, group1 + weights[index], group2, weights);

  // Try putting the current apple in group 2
  long diff2 =
      findMinDifference(index + 1, group1, group2 + weights[index], weights);

  // Return the minimum difference
  return min(diff1, diff2);
}

int main() {
  int n;
  // Read the number of apples
  cin >> n;

  vector<long> weights(n);
  // Read the weights of the apples
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }

  // Find the minimum difference starting from the first apple
  long minDifference = findMinDifference(0, 0, 0, weights);

  // Print the result
  cout << minDifference << endl;

  return 0;
}
