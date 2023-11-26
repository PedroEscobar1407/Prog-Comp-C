#include<bits/stdc++.h>
using namespace std;
int INF=-1;
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if (i-a >= 0){
            if (dp[i-a] != -1) dp[i] = max(dp[i], dp[i-a] + 1);
        }
        
        if(i-b >= 0){
            if (dp[i-b] != -1) dp[i] = max(dp[i], dp[i-b] + 1);
        } 
        if(i-c >= 0){
            if (dp[i-c] != -1) dp[i] = max(dp[i], dp[i-c] + 1);
        } 
    }
    cout << dp[n] << endl;
    return 0;
}