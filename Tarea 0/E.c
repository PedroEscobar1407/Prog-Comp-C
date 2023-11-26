#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int pruebas;
    cin >> pruebas;
    while(pruebas--){
        int n,m;
        string s1,s2;
        cin>>n>>m>>s1>>s2;
        reverse(s2.begin(),s2.end());
        string s = s1 + s2;
        int c = 0;
        for(int i=0; i<s.size();i++){
            if (s[i] == s[i-1]){
                c++;
            }
        }
        if (c <= 1){
            cout<<"YES"<<endl;
        }
        else {
            cout <<"NO"<<endl;
        }
    }
    return 0;
}