#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    unsigned int x,n;
    cin >> x >> n;
    set<unsigned int> pos;
    multiset<unsigned int> tramos;
    pos.insert(0);
    pos.insert(x);
    tramos.insert(x);
    
    for(int i=0;i<n;i++){
        unsigned int point;
        cin >> point;
        auto iter1 = pos.upper_bound(point);
        auto iter2 = iter1;
        --iter2;
        unsigned int espacio = *iter1 - *iter2;
        tramos.erase(tramos.find(espacio));
        tramos.insert(*iter1 - point);
        tramos.insert(point-*iter2);
        pos.insert(point);
        cout << *(--tramos.end()) << " ";
    }
    
    return 0;
}