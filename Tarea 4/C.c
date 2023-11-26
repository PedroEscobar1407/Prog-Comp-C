#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void update(int idx, int tl, int tr, int pos, ll val) {
        if (tl == tr) {
            tree[idx] = max(tree[idx], val);
            return;
        }

        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2 * idx, tl, tm, pos, val);
        } else {
            update(2 * idx + 1, tm + 1, tr, pos, val);
        }

        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
    }

    ll query(int idx, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) {
            return 0;
        }

        if (l <= tl && r >= tr) {
            return tree[idx];
        }

        int tm = (tl + tr) / 2;
        ll left_max = query(2 * idx, tl, tm, l, r);
        ll right_max = query(2 * idx + 1, tm + 1, tr, l, r);

        return max(left_max, right_max);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    SegmentTree seg_tree(n);
    ll max_sum = 0;

    for (int i = 0; i < n; i++) {
        ll current_sum = seg_tree.query(1, 1, n, 1, a[i] - 1) + b[i];
        max_sum = max(max_sum, current_sum);
        seg_tree.update(1, 1, n, a[i], current_sum);
    }

    cout << max_sum << endl;

    return 0;
}
C++
