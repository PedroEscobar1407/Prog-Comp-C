#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& trees, int n, int r, double mid) {
    double pos = trees[0] + mid;
    int routers = 1;
    for (int i = 1; i < n; i++) {
        if (abs(trees[i] - pos) > mid) {
            pos = trees[i] + mid;
            routers++;
            if (routers > r) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, n;
        cin >> r >> n;
        vector<int> trees(n);
        for (int i = 0; i < n; i++) {
            cin >> trees[i];
        }
        sort(trees.begin(), trees.end());
    double low = 0, high = trees[n - 1] - trees[0];
    while (high - low > 1e-9) {
        double mid = (low + high) / 2.0;
        if (isPossible(trees, n, r, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
        cout << fixed << setprecision(1) << high << endl;
    }
    return 0;
}