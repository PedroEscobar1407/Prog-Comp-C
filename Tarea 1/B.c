#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        priority_queue<long long> pq;
        long long resultado = 0;
        for(int j=0;j<m;j++){
            long long x;
            cin >> x;
            if(x==0){
                if(!pq.empty()){
                long long max = pq.top();
                resultado += max;
                pq.pop();
                }
            }
            else{
                pq.push(x);
            }
        }
        cout << resultado << endl;
    }
    return 0;
}