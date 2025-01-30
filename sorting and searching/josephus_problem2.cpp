#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    int size;

    FenwickTree(int n) {
        size = n + 1;
        tree.assign(size, 0);
    }

    void update(int index, int value) {
        for (; index < size; index += index & -index) {
            tree[index] += value;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

    int findKth(int k) {
        int low = 1, high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (query(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) {
        ft.update(i, 1); 
    }

    vector<int> ans;
    int index = 0; 

    for (int remaining = n; remaining > 0; remaining--) {
        index = (index + k) % remaining; 
        int child = ft.findKth(index + 1); 
        ans.push_back(child); 
        ft.update(child, -1); 
    }

    for (int child : ans) {
        cout << child << " ";
    }
    cout << endl;

    return 0;
}
