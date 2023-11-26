#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left;
    int right;
    int minVal;
    Node() : left(0), right(0), minVal(0) {}
};


void buildSegmentTree(vector<int>& arr, vector<Node>& tree, int node, int left, int right) {
    tree[node].left = left;
    tree[node].right = right;
    
    if (left == right) {
        tree[node].minVal = arr[left];
        return;
    }
    
    int mid = (left + right) / 2;
    buildSegmentTree(arr, tree, 2 * node, left, mid);
    buildSegmentTree(arr, tree, 2 * node + 1, mid + 1, right);
    
    tree[node].minVal = min(tree[2 * node].minVal, tree[2 * node + 1].minVal);
}


void updateValue(vector<Node>& tree, int node, int i, int x) {
    if (tree[node].left == tree[node].right) {
        tree[node].minVal = x;
        return;
    }
    
    int mid = (tree[node].left + tree[node].right) / 2;
    if (i <= mid) {
        updateValue(tree, 2 * node, i, x);
    } else {
        updateValue(tree, 2 * node + 1, i, x);
    }
    
    tree[node].minVal = min(tree[2 * node].minVal, tree[2 * node + 1].minVal);
}


int queryMin(vector<Node>& tree, int node, int i, int j) {
    if (tree[node].left == i && tree[node].right == j) {
        return tree[node].minVal;
    }
    
    int mid = (tree[node].left + tree[node].right) / 2;
    if (j <= mid) {
        return queryMin(tree, 2 * node, i, j);
    } else if (i > mid) {
        return queryMin(tree, 2 * node + 1, i, j);
    } else {
        int leftMin = queryMin(tree, 2 * node, i, mid);
        int rightMin = queryMin(tree, 2 * node + 1, mid + 1, j);
        return min(leftMin, rightMin);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<Node> tree(4 * n); 
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    buildSegmentTree(arr, tree, 1, 0, n - 1);
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, x;
            cin >> index >> x;
            updateValue(tree, 1, index - 1, x);
        } else if (type == 2) {
            int left, right;
            cin >> left >> right;
            int result = queryMin(tree, 1, left - 1, right - 1);
            cout << result << endl;
        }
    }
    
    return 0;
}