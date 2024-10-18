#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    ll n; cin >> n;

    set<ll> s;
    for(int i = 0; i<n; i++){
        ll a;
        cin >> a;
        s.insert(a);
        
    }
    cout << s.size();
    return 0;
}