#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> alturas(n);
    for (int i = 0; i < n; ++i) {
        cin >> alturas[i];
    }
    vector<int> dp(n+1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int j = i ;
        while (j < n && alturas[j] - alturas[i] <= x) {
            dp[i] = max(dp[i], 1 + dp[j]);
            j++;
        }
    }
    int resultado = *max_element(dp.begin(), dp.end());
    cout << resultado << endl;
    return 0;
}