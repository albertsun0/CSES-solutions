#include <iostream>
#include "vector"
using namespace std;
#define ll long long

int main () {
    ll n;
    cin >> n;
    ll count = 0;
    ll total = n;
    for(int i = 1; i<=n-1; i++){
        ll temp;
        cin >> temp;
        count+=temp;
        total+=i;
    }
    cout << total-count;
    return 0;
}