#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int tree[4 * MAX][26];
string s;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node][s[start] - 'a']++;
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        for(int i = 0; i < 26; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

void update(int node, int start, int end, int idx, char prev, char newChar) {
    if(start == end) {
        tree[node][prev - 'a']--;
        tree[node][newChar - 'a']++;
    }
    else {
        int mid = (start + end) / 2;
        if(idx <= mid) {
            update(2 * node, start, mid, idx, prev, newChar);
        }
        else {
            update(2 * node + 1, mid + 1, end, idx, prev, newChar);
        }
        for(int i = 0; i < 26; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

int query(int node, int start, int end, int l, int r, char c) {
    if(r < start || end < l) {
        return 0;
    }
    if(l <= start && end <= r) {
        return tree[node][c - 'a'];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r, c);
    int p2 = query(2 * node + 1, mid + 1, end, l, r, c);
    return (p1 + p2);
}

int main() {
    cin >> s;
    int n = s.size();
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int idx;
            char newChar;
            cin >> idx >> newChar;
            idx--; 
            if(s[idx] != newChar) {
                update(1, 0, n - 1, idx, s[idx], newChar);
                s[idx] = newChar;
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int res = 0;
            for(char c = 'a'; c <= 'z'; c++) {
                int cnt = query(1, 0, n - 1, l, r, c);
                if(cnt > 0) {
                    res++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}