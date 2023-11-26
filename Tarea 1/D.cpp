#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> orden;
    for(int i=0; i<n; i++){
        int resto = x - arr[i];
        if(orden.find(resto)!= orden.end()){
            cout << orden[resto] + 1 << " " << i + 1 << endl;
            return 0;
        }
        orden[arr[i]] = i;
        
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
    
}