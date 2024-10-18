#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; cin >> n;
    vector<ll> v;
    for(int i = 0; i<n; i++){
        ll a; cin>> a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    
    ll smallest = 1;

    for(int i = 0; i< n; i++){
        if(v[i] > smallest){
            cout << smallest;
            return 0;
        }
        if(v[i] <= smallest){
            smallest += v[i];
        }
    }
    cout << smallest;

    return 0;
}