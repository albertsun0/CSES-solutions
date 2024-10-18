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
    ll ans = 0;
    ll cur = 0;
    ll maxn = -1e9;
    for(int i = 0; i<n ;i++){
        ll a; cin >>a;
        cur +=a;
        if(cur < 0){
            cur = 0;
        }
        ans = max(ans, cur);
        maxn = max(maxn,a);
    }
    if(maxn < 0){
        cout << maxn;
        return 0;;
    }
    cout << ans;

    return 0;
}