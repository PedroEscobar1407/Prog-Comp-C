#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll h = 0, a = 0, r = 0, d = 0 ;
  vector <ll> costo(n);
  for (int i = 0; i < n; i++) {
    cin >> costo[i];
  }
  for (int i = 0; i < n; i++){
    if (s[i] == 'h') {
        h = costo[i] + h;
    }if (s[i] == 'a') {
        a = min(h, a+costo[i]);
    } if (s[i] == 'r'){
        r = min(a, r + costo[i]);
    }if (s[i] == 'd'){
        d = min(r, d + costo[i]);
    }
  }

  cout << d << endl;
  return 0;
}