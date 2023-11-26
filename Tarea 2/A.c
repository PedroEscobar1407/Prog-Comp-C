#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long n, long long t, long long arr[]){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += mid/arr[i];
        if(sum >= t) return true;
    }
    return false;
}

int main(){
    long long n, t;
    cin >> n >> t;
    long long arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long low = 1, high = 1e18, ans = 0;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(check(mid, n, t, arr)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans << endl;
    return 0;
}