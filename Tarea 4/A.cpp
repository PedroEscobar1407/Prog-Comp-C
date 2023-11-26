#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, a[MAXN], tree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int val) {
    if (start == end) {
        return start;
    } else {
        int mid = (start + end) / 2;
        if (val <= tree[2 * node]) {
            return query(2 * node, start, mid, val);
        } else {
            return query(2 * node + 1, mid + 1, end, val - tree[2 * node]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        int idx = query(1, 1, n, p);
        cout << a[idx] << " ";
        update(1, 1, n, idx, 0);
    }
    return 0;
}