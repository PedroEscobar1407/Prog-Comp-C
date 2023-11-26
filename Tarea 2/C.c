#include<bits/stdc++.h>
using namespace std;

long long q;
long long k, n, a, b;

bool check(long long m, long long a, long long b, long long k, long long n){
    if(k - m*a > (n-m)*b){
        return true;
    } 
    else{
        return false;
    }
    
}

int main(){
    cin >> q;
    while (q--){
        cin >> k >> n >> a >>b;
        long long l = 0;
        long long r = n;
        long long m = 0;
        int res = -1;
        while (l <= r){
            m=(l+r)/ 2;
            if (check(m,a,b,k,n)){
                l = m+1;
                res = m;
            }
            else {
                r = m - 1;
            }
        }
       cout << res << endl;
     }
    return 0;
}