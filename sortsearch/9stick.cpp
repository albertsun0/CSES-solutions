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
    ll sum = 0;
    vector<ll> v;
    for(int i = 0; i<n; i++){
        ll a; cin>> a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    ll mid = v[v.size()/2];
    // if(n%2 == 1){
        for(int i = 0; i<v.size(); i++){
            sum+=abs(mid-v[i]);
        }
        cout << sum;
    // }
    // else{
    //     if()
    // }
    return 0;
}