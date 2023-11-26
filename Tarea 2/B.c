#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<long long> &arr, int n, int k) {
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false;
        sum += arr[i];
        if (sum > mid) {
            count++;
            sum = arr[i];
        }
    }
    count++;
    return count <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long start = 1;
    long long end = 2e14;
    long long answer = 0;
    while (start < end) {
        long long mid = (start + end)/ 2;
        if (check(mid, arr, n, k)) {
            answer = mid;
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}